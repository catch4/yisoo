// 백준 154862번 퇴사2

#include <cstring>
#include <iostream>
#define MAX 1500001

using namespace std;

int dp[MAX], t[MAX], p[MAX], n;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
}

int solve()
{
    int ret = 0;

    for (int i = 1; i <= n + 1; i++) {
        ret = max(ret, dp[i]);
        if (i + t[i] > n + 1)
            continue;

        dp[i + t[i]] = max(ret + p[i], dp[i + t[i]]);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    input();
    cout << solve();
    return 0;
}