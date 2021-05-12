// 백준 17089번 세-친구
/*
1. 친구가 2명 이상
2. 사이클 존재 ([a][b], [b][c], [c][a])
3. 최소값 확인

*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define MAX 4001

using namespace std;

int n, m;
vector<int> person[MAX];
map<vector<int>, bool> relation;
bool arr[MAX][MAX];
const int INIT = 12001;
int answer = INIT;

void input()
{
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        person[a].push_back(b);
        person[b].push_back(a);
        arr[a][b] = arr[b][a] = 1;
    }
}

bool isValid(int cur)
{
    return person[cur].size() >= 2;
}

vector<int> construct(int a, int b, int c)
{
    vector<int> rel = { a, b, c };
    sort(rel.begin(), rel.end());
    return rel;
}

void solve(int cur)
{
    if (!isValid(cur))
        return;

    for (int f1 : person[cur]) {
        if (!isValid(f1))
            continue;
        for (int f2 : person[cur]) {
            if (!isValid(f2) || f1 == f2)
                continue;

            vector<int> rel = construct(cur, f1, f2);

            if (relation[rel] || !arr[f1][f2])
                continue;

            relation[rel] = 1;
            int val = person[cur].size() + person[f1].size() + person[f2].size() - 6;
            answer = min(answer, val);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    if (answer == INIT)
        cout << -1;
    else
        cout << answer;
    return 0;
}