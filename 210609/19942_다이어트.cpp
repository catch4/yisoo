// 백준 19942번 다이어트

// 브루트포스
// n이 15라 비트마스킹했지만, 로직상 큰 의미는 없었다...!

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Nut {
    int p, f, s, v, c;

    Nut operator+(const Nut& nut)
    {
        return { p + nut.p, f + nut.f, s + nut.s, v + nut.v, c + nut.c };
    }
};

int mp, ms, mf, mv, n;
Nut arr[16];
vector<string> answers;
int lowestCost = 1e9;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;
    }
}

bool isOver(Nut nut)
{
    return nut.p >= mp && nut.f >= mf && nut.s >= ms && nut.v >= mv;
}

string convert(int select)
{
    string ret;
    for (int i = 0; i < 15; i++) {
        int now = 2 << i;
        if (select & now) {
            ret += to_string(i + 1) + " ";
        }
    }
    return ret;
}

void solve(int select, int cur, Nut nut)
{
    if (nut.c > lowestCost)
        return;
    if (isOver(nut)) {
        string ret = convert(select);
        if (nut.c < lowestCost) {
            answers.clear();
            answers.push_back(ret);
            lowestCost = nut.c;
        } else if (nut.c == lowestCost) {
            answers.push_back(ret);
        }
        return;
    }

    for (int i = cur + 1; i < 15; i++) {
        int now = 2 << i;
        if (!(select & now)) {
            int newSelect = select | now;
            solve(newSelect, i, nut + arr[i]);
        }
    }
    return;
}

void print()
{
    if (answers.size() == 0) {
        cout << "-1\n\n";
        return;
    }

    sort(answers.begin(), answers.end());
    cout << lowestCost << "\n";
    cout << answers[0];
}

int main()
{
    input();
    Nut nut = { 0, 0, 0, 0, 0 };
    solve(0, -1, nut);
    print();
    return 0;
}