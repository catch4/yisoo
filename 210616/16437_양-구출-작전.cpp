// 백준 16437번 양-구출-작전

// 경로가 유일하므로 트리 모양
// 게다가 늑대는 1인분밖에 못 먹으므로 트리 dp 형태 가능.

#include <cstring>
#include <iostream>
#include <vector>
#define MAX 123457

using namespace std;

typedef long long ll;

int n, wolf[MAX], sheep[MAX];
vector<int> child[MAX];
ll dp[MAX];
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char op;
    int a, p;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> op >> a >> p;
        if (op == 'W')
            wolf[i] = a;
        else
            sheep[i] = a;
        child[p].push_back(i);
    }
}

ll solve(int cur)
{
    if (child[cur].size() == 0)
        return dp[cur] = sheep[cur];

    ll& ret = dp[cur];
    if (ret != -1)
        return ret;

    ret = sheep[cur];
    ll sum = 0;
    for (int ch : child[cur]) {
        sum += solve(ch);
    }

    ret += max((ll)0, sum - wolf[cur]);

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    input();
    cout << solve(1);
    return 0;
}
