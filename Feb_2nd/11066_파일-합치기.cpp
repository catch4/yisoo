// 백준 11066번 파일-합치기

#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int tc, k;
int book[501], sum[501], dp[501][501];

const int INF = INT_MAX;

void init()
{
    memset(sum, 0, sizeof(sum));
    memset(dp, 0, sizeof(dp));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;

    while (tc--) {
        cin >> k;
        init();
        for (int i = 1; i <= k; i++) {
            cin >> book[i];
            sum[i] = sum[i - 1] + book[i];
        }

        for (int j = 2; j <= k; j++) {
            for (int i = j - 1; i > 0; i--) {
                dp[i][j] = INF;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] += sum[j] - sum[i - 1];
            }
        }
        cout << dp[1][k] << "\n";
    }
    return 0;
}