// 백준 16172번 나는-친구가-적다(Large)

// kmp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string n, k;

string removeNumber(string str)
{
    string ret;
    for (char c : str)
        if (c < '0' || c > '9')
            ret += c;
    return ret;
}

vector<int> getPartialMatch(string str)
{
    int m = str.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (str[begin + matched] == str[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

// kmp
bool isIncluded()
{
    int len = n.size(), m = k.size();

    // 부분 일치 테이블 or 실패 함수 구하기.
    vector<int> pi = getPartialMatch(k);

    int begin = 0, matched = 0;
    while (begin + m <= len) {
        if (matched < m && n[begin + matched] == k[matched]) {
            matched++;

            if (matched == m)
                return true;
        }

        else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    n = removeNumber(n);
    cout << isIncluded();

    return 0;
}