// 백준 20055번 컨베이어 벨트 위의 로봇

#include <deque>
#include <iostream>

using namespace std;
typedef pair<int, bool> pi;

int n, k, z;
deque<pi> dq;

void rotate()
{
    dq.push_front({ dq.back().first, 0 });
    dq.pop_back();
    dq[n].second = 0;

    if (dq[n - 1].second) {
        dq[n - 1].second = 0;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (dq[i].second && dq[i + 1].first >= 1 && !dq[i + 1].second) {
            dq[i + 1].first--;
            if (dq[i + 1].first == 0)
                z++;
            dq[i + 1].second = 1;
            dq[i].second = 0;
        }
    }
    if (dq.front().first >= 1 && !dq.front().second) {
        dq.front().first--;
        dq.front().second = 1;
        if (dq.front().first == 0)
            z++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int a;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a;
        dq.push_back({ a, 0 });
    }
    int ans = 0;
    while (z < k) {
        ans++;
        rotate();
    }

    cout << ans;
    return 0;
}