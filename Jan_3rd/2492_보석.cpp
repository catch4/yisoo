// 백준 2492번 보석

#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> pi;

int n, m, t, k;
pi stone[101];
int ans, ax, ay;

int solve(int x, int y)
{
    int ret = 0;
    for (int i = 0; i < t; i++) {
        if (x <= stone[i].first && stone[i].first <= x + k && y <= stone[i].second && stone[i].second <= y + k)
            ret++;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t >> k;

    int x, y;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        stone[i] = { x, y };
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (stone[i].first + k > n) {
                x = n - k;
            } else {
                x = stone[i].first;
            }
            if (stone[j].second + k > m) {
                y = m - k;
            } else {
                y = stone[j].second;
            }

            int cnt = solve(x, y);
            if (cnt > ans) {
                ans = cnt;
                ax = x, ay = y + k;
            }
        }
    }
    cout << ax << " " << ay << endl;
    cout << ans;
    return 0;
}