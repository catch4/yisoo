// 백준 11812번 K진트리

#include <iostream>

using namespace std;
typedef long long ll;

int k, q;
ll n, a, b;

ll getParent(ll val)
{
    return (val + k - 2) / k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> q;

    while (q--) {
        cin >> a >> b;

        if (a > b)
            swap(a, b);
        if (k == 1) {
            cout << b - a << "\n";
            continue;
        }
        int cnt = 0;

        while (a != b) {
            while (a < b) {
                b = getParent(b);
                cnt++;
            }

            while (a > b) {
                a = getParent(a);
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}