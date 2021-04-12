// 백준 12904번 A와 B

// T를 기준으로 S가 될 수 있는지를 판단.
// 길이가 같아질 때까지 삭제.

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;

    bool flag;
    while (s.size() != t.size()) {
        flag = t.back() == 'A' ? false : true;
        t = t.substr(0, t.size() - 1);

        if (flag)
            reverse(t.begin(), t.end());
    }
    cout << (s == t);

    return 0;
}