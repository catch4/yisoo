// 백준 20120번 호반우와-리듬게임

#include <iostream>

#define MAX 1001

using namespace std;
typedef long long ll;

ll dp[MAX][MAX];
int n, arr[MAX];
ll ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1e14;
        }
    }

    dp[1][0] = 0;
    dp[1][1] = arr[1];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1] * (j + 1));

            if (i + 2 > n) {
                dp[n][0] = max(dp[n][0], dp[i][j]);
                continue;
            }
            dp[i + 2][1] = max(dp[i + 2][1], dp[i][j] + arr[i + 2]);

            if (i + 3 > n) {
                dp[n][0] = max(dp[n][0], dp[i][j]);
                continue;
            }

            if (i == 1 && j == 0)
                continue;
            dp[i + 3][1] = max(dp[i + 3][1], dp[i][j] + arr[i + 3]);
        }
    }

    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}
