// 백준 2616번 소형기관차

// dp + 누적합

#include <iostream>
#define MAX 50002
using namespace std;

int n, k;
int trainSum[MAX];
int dp[3][MAX];

void input()
{
    cin >> n;
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        trainSum[i] = trainSum[i - 1] + num;
    }
    cin >> k;
}

int cal(int idx)
{
    return trainSum[idx] - trainSum[idx - k];
}

int solve()
{
    int ret = 0;

    for (int i = 0; i < 3; i++) {
        // 최소 시작점
        int start = i * k;
        // 최대 끝점 (n개에서 최소 남은 기차 빼기)
        int end = n - (2 - i) * k;
        for (int j = start; j <= end; j++) {
            if (i == 0)
                dp[i][j] = max(dp[i][j - 1], cal(j));
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + cal(j));
            ret = max(ret, dp[i][j]);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << solve();
    return 0;
}