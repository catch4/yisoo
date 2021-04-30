// 백준 1484번 다이어트

/*
투포인터

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int g;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> g;
    vector<int> ret;

    int l = 1, r = 1;

    while (r < 1e5 && (l <= r)) {
        int val = r * r - l * l;
        if (val > g) {
            l++;
        } else if (val < g) {
            r++;
        } else {
            ret.push_back(r);
            r++;
        }
    }

    if (ret.size() == 0)
        cout << -1;
    else {
        for (int i : ret) {
            cout << i << "\n";
        }
    }
    return 0;
}