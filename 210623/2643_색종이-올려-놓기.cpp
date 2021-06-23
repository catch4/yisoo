// 백준 2643번 색종이-올려-놓기

// dp, lis

#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> pi;

int n, h, w;
pi rectangle[101];
int dp[101];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w >> h;
        rectangle[i] = { min(w, h), max(w, h) };
    }
}

bool isOver(int i, int j)
{
    return rectangle[i].first >= rectangle[j].first
        && rectangle[i].second >= rectangle[j].second;
}

int solve()
{
    sort(rectangle, rectangle + n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (isOver(i, j)) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    input();
    cout << solve();
    return 0;
}