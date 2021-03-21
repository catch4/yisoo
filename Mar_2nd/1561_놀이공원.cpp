// 백준 1561번 놀이공원

// 프로그래머스 이분탐색과 거의 유사한 문제. => 이분탐색

/*
1. 이분탐색으로 마지막 인원의 탑승 시간 구하기
2. N명에서 탑승시간 이전까지 탑승하는 인원 수를 제외 (제외하게 되면 탑승시간에 누가 탑승하는지만 파악하면 된다.)
3. 탑승시간 % 기구별시간 == 0이면 이는 탑승시간에 타는 경우이므로 마지막 인원이 탑승하는 놀이기구 번호 파악만 하면 된다.
*/

#include <iostream>

using namespace std;
typedef long long ll;

int n, m;
int time[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> time[i];
    }

    if (n <= m) {
        cout << n;
        return 0;
    }

    ll l = 0, r = 6e14 + 1;

    ll timeAns = r;
    // 1.
    while (l <= r) {
        ll mid = (l + r) / 2;

        // n<=m이면 0분에는 m명이 탑승할 수 있다.
        ll tmp = m;

        for (int i = 1; i <= m; i++) {
            tmp += (mid / time[i]);
        }

        if (tmp >= n) {
            timeAns = min(timeAns, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    int ans;

    // 2.
    ll tmp = m;
    for (int i = 1; i <= m; i++) {
        tmp += (timeAns - 1) / time[i];
    }

    ll remain = n - tmp;
    ll cnt = 0;

    // 3.
    for (int i = 1; i <= m; i++) {
        if (timeAns % time[i] == 0)
            cnt++;
        if (cnt == remain) {
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}