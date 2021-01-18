// 백준 2532번 먹이사슬

#include <algorithm>
#include <iostream>
#include <vector>
#define x first
#define y second

using namespace std;
typedef pair<int, int> pi;

int n, answer;
vector<pi> arr;
vector<int> lis;

bool cmp(pi a, pi b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x < b.x;
}

bool cmp2(int a, int b)
{
    return a >= b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int idx;
    for (int i = 0; i < n; i++) {
        pi a;
        cin >> idx >> a.x >> a.y;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end(), cmp);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    lis.push_back(arr[0].y);

    for (int i = 1; i < arr.size(); i++) {

        auto it = lower_bound(lis.begin(), lis.end(), arr[i].y, cmp2);
        if (it == lis.end())
            lis.push_back(arr[i].y);
        else
            *it = arr[i].y;
    }

    cout << lis.size();
    return 0;
}