// 백준 2109번 순회강연

// 그리디로 정렬
// 돈 많이 주는 곳부터 방문.
// 같은 날이라면 이전에 가능한 날로 체크

#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 10001
using namespace std;

struct Lec {
    int day, pay;

    bool operator<(const Lec& lec)
    {
        if (pay == lec.pay)
            return day < lec.day;
        return pay > lec.pay;
    }
};

int n, d, p;
vector<Lec> arr;
int check[MAX];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        arr.push_back({ d, p });
    }
}

int find(Lec lec)
{
    int day = lec.day;
    int pay = lec.pay;

    for (int i = day; i > 0; i--) {
        if (check[i] == 0) {
            return i;
        }
    }

    return -1;
}

int solve()
{
    sort(arr.begin(), arr.end());

    for (Lec lec : arr) {
        int idx = find(lec);

        if (idx == -1)
            continue;
        check[idx] = lec.pay;
    }

    int ret = 0;

    for (int i = 0; i < MAX; i++) {
        ret += check[i];
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();
    cout << solve();
    return 0;
}