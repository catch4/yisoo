// 백준 20366번 같이-눈사람-만들래

// Two pointer
// O(n^3)

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int n, arr[601];
int ans = 2e9 + 1;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void check(int first, int second)
{
    int val = arr[first] + arr[second];

    int l = 0, r = n - 1;

    while (l < r) {
        while (l == first || l == second) {
            l++;
        }

        while (r == first || r == second) {
            r--;
        }
        if (l >= r)
            return;
        int now = arr[r] + arr[l];

        ans = min(ans, abs(now - val));

        if (now >= val) {
            r--;
        } else {
            l++;
        }
    }
}

void solve()
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            check(i, j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    sort(arr, arr + n);

    solve();

    cout << ans;
    return 0;
}