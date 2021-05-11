// 백준 11049번 행렬-곱셈-순서

/*
DP
구간별로 최적의 경우를 찾으면 된다.
*/

#include <climits>
#include <cstring>
#include <iostream>

#define MAX 501
#define r first
#define c second
using namespace std;
typedef pair<int, int> pi;

int n;
pi arr[MAX];
int dp[MAX][MAX];

void input()
{
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].r >> arr[i].c;
    }
}

int solve(int s, int e)
{
    int& ret = dp[s][e];
    if (s == e)
        return ret = 0;

    if (e == s + 1) {
        ret = arr[s].r * arr[s].c * arr[e].c;
        return ret;
    }
    if (ret != -1)
        return ret;

    ret = INT_MAX;
    for (int i = s; i < e; i++) {
        ret = min(ret, solve(s, i) + solve(i + 1, e) + arr[s].r * arr[i].c * arr[e].c);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << solve(0, n - 1);

    return 0;
}