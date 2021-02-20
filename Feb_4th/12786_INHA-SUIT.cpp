// 백준 12786번 INHA SUIT

/*
n이 100, 높이가 20이므로 한 칸씩 탐색하는 브루트포스로 가능.

현재 칸이 구멍이면 O,A,B,C 기능이 가능한 지 확인, 안되면 T로 이동
마지막 칸에서 가능한 경우 중 제일 작은 거 확인

*/

#include <iostream>

using namespace std;

int n, t, m, h;
bool tree[101][21];
int dp[101][21];

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;

    // 나무 구멍 표시
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> h;
            tree[i][h] = 1;
        }
        for (int j = 0; j < 21; j++) {
            dp[i][j] = INF;
        }
    }

    tree[0][1] = 1;
    dp[0][1] = 0;

    // 나무 순서대로 구멍 확인
    for (int i = 0; i < n; i++) {

        // 현재 나무 중 가능한 구멍 확인
        for (int j = 1; j < 21; j++) {
            if (!tree[i][j])
                continue;

            // O
            if (tree[i + 1][j])
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

            // A
            if (j != 20 && tree[i + 1][j + 1])
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            // C
            if (tree[i + 1][j - 1])
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);

            // B
            int height = j >= 10 ? 20 : 2 * j;

            if (tree[i + 1][height])
                dp[i + 1][height] = min(dp[i + 1][height], dp[i][j]);

            // T로 가능한 경우 확인
            for (int k = 1; k < 21; k++) {
                if (!tree[i + 1][k])
                    continue;
                // 어차피 O,A,B,C는 +1 안하므로 더 작은 수가 나오므로 경우 구분 안함.
                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + 1);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < 21; i++) {
        ans = min(ans, dp[n][i]);
    }

    if (ans == INF || ans > t) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}