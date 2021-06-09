// 백준 9935번 문자열-폭발

#include <deque>
#include <iostream>
#include <string>
using namespace std;

string solve(string obj, string explode)
{
    string ret;
    int len = explode.size();
    for (char c : obj) {
        ret += c;

        if (ret.size() < len)
            continue;

        string suffix = ret.substr(ret.size() - len);
        if (suffix == explode) {
            for (int i = 0; i < len; i++)
                ret.pop_back();
        }
    }
    if (ret.size() == 0)
        ret = "FRULA";
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str, explode;
    cin >> str >> explode;

    cout << solve(str, explode);

    return 0;
}