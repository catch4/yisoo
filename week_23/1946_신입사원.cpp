// 백준 1946번 신입사원

#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> pi;

int n;
pi arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        sort(arr, arr + n);

        int minVal = arr[0].second;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i].second < minVal) {
                ans++;
                minVal = arr[i].second;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}