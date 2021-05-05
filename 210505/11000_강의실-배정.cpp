// 백준 11000번 강의실-배정

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Lec {
    int start, end;

    bool operator<(const Lec& lec)
    {
        return start < lec.start;
    }
};

int n;
Lec arr[200001];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].start >> arr[i].end;
}

int solve()
{
    sort(arr, arr + n);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        Lec lec = arr[i];
        if (pq.empty()) {
            pq.push(lec.end);
            continue;
        }
        int time = pq.top();
        if (time <= lec.start) {
            pq.pop();
        }
        pq.push(lec.end);
    }

    return pq.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << solve();
    return 0;
}