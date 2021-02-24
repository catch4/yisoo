// 백준 17251번 힘-겨루기

#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int max = 0;
    int num;
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > max) {
            max = num;
            idx.clear();
            idx.push_back(i);
        } else if (num == max) {
            idx.push_back(i);
        }
    }

    int l, r;
    if (idx.size() == 1) {
        l = idx.back();
        r = n - l - 1;
    } else {
        l = idx.front();
        r = n - idx.back() - 1;
    }

    if (l == r) {
        cout << "X";
    } else if (l < r) {
        cout << "R";
    } else {
        cout << "B";
    }

    return 0;
}