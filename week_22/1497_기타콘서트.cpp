// 백준 1497번 기타콘서트

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int n, m;
ll arr[11];
string s, t;
int ans, val;

int get(ll bit)
{
    int ret = 0;

    while (bit) {
        if (bit % 2)
            ret++;
        bit /= 2;
    }

    return ret;
}

void solve(int cnt, ll total, int idx)
{
    int ret = get(total);

    if (val < ret) {
        ans = cnt;
        val = ret;
    } else if (val == ret) {
        ans = min(cnt, ans);
    }

    if (idx == n) {
        return;
    }
    solve(cnt + 1, total | arr[idx], idx + 1);
    solve(cnt, total, idx + 1);
}

ll make(string t)
{
    ll ret = 0;
    for (int i = m - 1; i >= 0; i--) {
        if (t[i] == 'Y')
            ret += pow(2, i);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s >> t;

        arr[i] = make(t);
    }

    solve(0, 0, 0);

    if (val == 0) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}