// 백준 13418번 학교-탐방하기

// MST - 크루스칼 알고리즘
// 오르막길 기준, 내리막길 기준 계산해서 차이 반환

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct road {
    int c, a, b;

    bool operator<(const road& r)
    {
        return c < r.c;
    }
};

int n, m;
vector<road> course;
int p[1001];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i <= m; i++) {
        cin >> a >> b >> c;
        course.push_back({ c, a, b });
    }
}

int find(int cur)
{
    if (p[cur] == cur)
        return cur;
    return p[cur] = find(p[cur]);
}

bool merge(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a == b)
        return false;
    if (a > b)
        swap(a, b);
    p[b] = a;
    return true;
}

void init()
{
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
}

// isUp이 참이면 오르막길 기준
int calTime(bool isUp)
{
    init();
    // 내리막길 기준일 경우 내리막길부터 하도록 뒤집기
    if (!isUp)
        reverse(course.begin(), course.end());

    int k = 0;
    int cnt = 0;

    for (int i = 0; i < course.size(); i++) {
        if (merge(course[i].a, course[i].b)) {
            cnt++;
            k += 1 - course[i].c;
        }
        if (cnt == n)
            break;
    }
    return k * k;
}

int main()
{
    input();
    sort(course.begin(), course.end());
    cout << calTime(1) - calTime(0);
    return 0;
}