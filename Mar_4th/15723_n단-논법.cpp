// 백준 15723번 n단-논법

// 간단하 플로이드 와샬

#include <iostream>
#include <string>

using namespace std;

int n, m;
bool arr[26][26];

int calIdx(char c)
{
    return c - 'a';
}

void inputN()
{
    cin >> n;
    cin.ignore();
    string str;
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        int first = calIdx(str[0]);
        int second = calIdx(str.back());

        arr[first][second] = true;
    }
}

void solve()
{
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (arr[i][k] && arr[k][j])
                    arr[i][j] = 1;
            }
        }
    }
}

void inputM()
{
    cin >> m;
    cin.ignore();
    string str;
    for (int i = 0; i < m; i++) {

        getline(cin, str);
        int first = calIdx(str[0]);
        int second = calIdx(str.back());
        if (arr[first][second])
            cout << "T\n";
        else
            cout << "F\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    inputN();
    solve();
    inputM();
    return 0;
}