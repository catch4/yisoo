// 백준 13422번 도둑

#include <iostream>
#define MAX 100001
using namespace std;

int t, n, m, k;

int house[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int ans = 0;
        for (int i = 0; i < n; i++)
            cin >> house[i];

        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += house[i];
        }
        if (sum < k)
            ans++;
        if (n > m) {
            for (int i = 0; i < n - 1; i++) {
                int idx = i + m >= n ? i + m - n : i + m;
                sum += house[idx] - house[i];
                if (sum < k)
                    ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}