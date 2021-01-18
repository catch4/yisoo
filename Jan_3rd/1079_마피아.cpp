// 백준 1079번 마피아

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int n, e;

int r[17][17];
bool check[17];
int ans;
int guilty[17];

bool cmp(pi a, pi b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int get()
{
    int ans = 0, val = -1;
    for (int i = 0; i < n; i++) {
        if (check[i])
            continue;
        if (val >= guilty[i])
            continue;
        val = guilty[i];
        ans = i;
    }
    return ans;
}

void solve(int people, int cnt)
{
    if (check[e] || people == 1) {
        ans = max(ans, cnt);
        return;
    }
    if (people % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (check[i])
                continue;
            check[i] = 1;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                guilty[j] += r[i][j];
            }
            solve(people - 1, cnt + 1);
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                guilty[j] -= r[i][j];
            }
            check[i] = 0;
        }
    } else {
        int idx = get();
        check[idx] = 1;
        solve(people - 1, cnt);
        check[idx] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int g;
    for (int i = 0; i < n; i++) {
        cin >> guilty[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> r[i][j];
        }
    }
    cin >> e;

    solve(n, 0);
    cout << ans;
    return 0;
}