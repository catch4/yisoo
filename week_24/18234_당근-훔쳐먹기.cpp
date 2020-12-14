// 백준 18234번 당근 훔쳐먹기

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

int n, t;
ll w[200001], p[200001];
vector<pi> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> p[i];

        arr.push_back({ p[i], w[i] });
    }

    sort(arr.begin(), arr.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += arr[i].second + (t - n + i) * arr[i].first;
    }

    cout << ans;

    return 0;
}