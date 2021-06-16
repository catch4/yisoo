// 백준 1477번 휴게소-세우기

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, l;
vector<int> station;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> l;

    station.push_back(0);
    int d;
    for (int i = 0; i < n; i++) {
        cin >> d;
        station.push_back(d);
    }
    station.push_back(l);
    sort(station.begin(), station.end());
}

bool isUnderDist(int dist)
{
    int sum = 0;
    for (int i = 0; i < station.size() - 1; i++) {
        int diff = station[i + 1] - station[i];
        int val = diff / dist;
        sum += val;
        if (diff % dist == 0)
            sum--;
    }
    return sum <= m;
}

int solve()
{
    int low = 0, hi = l;
    int answer = 1e9;
    while (low <= hi) {
        int mid = low + (hi - low) / 2;

        if (isUnderDist(mid)) {
            answer = min(answer, mid);
            hi = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main()
{
    input();
    cout << solve();
    return 0;
}