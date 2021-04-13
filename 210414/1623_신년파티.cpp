// 백준 1623번 신년파티

// 트리 dp + 특정 노드 찾기
/*
1. 트리 dp
 - int go(int check, int cur)
 => cur : 직원 번호
 => check : 참여 여부 

2. 참여 직원 찾기
- void find(int pCheck, int cur, vector<int>& arr)
=> pCheck : 상사의 파티 참여 여부
=> cur : 직원 번호

1) 상사가 참여했으면 직원은 무조건 참여 못함. 
2) 상사가 미참여했으면 직원은 참여 선택 가능.(참여하는 경우 점수가 더 크면 참여)

*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX 200001

using namespace std;

int n, dp[MAX][2], p[MAX];
vector<int> child[MAX];
const int MIN = -2e9 + 1;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int par;
    for (int i = 2; i <= n; i++) {
        cin >> par;
        child[par].push_back(i);
    }
}

// 트리 dp
int go(int check, int cur)
{
    int& ret = dp[cur][check];

    if (ret != MIN)
        return ret;

    if (child[cur].size() == 0) {
        if (check) {
            return ret = p[cur];
        } else {
            return ret = 0;
        }
    }
    ret = check ? p[cur] : 0;
    for (int c : child[cur]) {
        if (check) {
            ret += go(0, c);
        } else {
            ret += max(go(0, c), go(1, c));
        }
    }

    return ret;
}

// 참여 직원 찾기
void find(int pCheck, int cur, vector<int>& arr)
{
    int check = 0;
    if (!pCheck) {
        if (dp[cur][1] >= dp[cur][0]) {
            check = 1;
            arr.push_back(cur);
        }
    }
    for (int c : child[cur]) {
        find(check, c, arr);
    }
    return;
}

// 참여 직원 print
void print(int check)
{
    vector<int> arr;
    if (check)
        arr.push_back(1);
    for (int c : child[1]) {
        find(check, c, arr);
    }
    sort(arr.begin(), arr.end());
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // 날라리 포인트는 음수도 있으므로 최소 합계보다 작게 초기화
    for (int i = 0; i < MAX; i++) {
        dp[i][0] = dp[i][1] = MIN;
    }
    input();

    cout << go(1, 1) << " " << go(0, 1) << endl;
    print(1);
    print(0);
    return 0;
}