// 백준 17136번 색종이-붙이기

/*
백트래킹
1. 현재 좌표에서의 우하단 방향으로 정사각형 최대 크기 확인
2. 최대 크기부터 1까지 하나씩 줄여나가면서 방문.
3. dfs로 최소 색종이 개수 확인

*/

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 1;
bool map[10][10];
int type[5] = { 5, 5, 5, 5, 5 };
int total;
int ans = INF;

void go(int cnt, int x, int y);

// 범위 내인지 확인
bool check(int x, int y)
{
    if (x >= 0 && x < 10 && y >= 0 && y < 10)
        return true;
    return false;
}

// x,y으로부터 size만큼의 정사각형이 되는지 확인
bool checkRange(int x, int y, int size)
{
    if (!check(x + size, y + size))
        return false;

    for (int i = x; i <= x + size; i++) {
        if (!map[i][y + size])
            return false;
    }

    for (int i = y; i <= y + size; i++) {
        if (!map[x + size][i])
            return false;
    }
    return true;
}

// x,y 기준 정사각형 크기 계산
int getSquareSize(int x, int y)
{
    for (int i = 1; i <= 4; i++) {
        if (!checkRange(x, y, i))
            return i;
    }
    return 5;
}

// 다음 방문할 좌표 계산 ((x,y)부터 len만큼 떨어진 좌표 구해준다.)
void next(int cnt, int x, int y, int len)
{
    if (y + len == 10) {
        go(cnt, x + 1, 0);
    } else {
        go(cnt, x, y + len);
    }
}

// 방문
void fill(int x, int y, int len, bool val)
{
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            map[i][j] = val;
        }
    }
}

// 백트래킹
void go(int cnt, int x, int y)
{
    if (cnt > total)
        return;

    // 모든 점을 지나왔으면 최소 개수 계산
    if (x == 10) {

        int ret = 0;
        for (int i : type)
            ret += 5 - i;
        ans = min(ans, ret);
        return;
    }

    if (!map[x][y]) {
        next(cnt, x, y, 1);
        return;
    }
    int size = getSquareSize(x, y);

    // size 줄여나가면서 확인
    for (int i = size; i >= 1; i--) {
        if (type[i - 1] == 0)
            continue;
        type[i - 1]--;
        fill(x, y, i, 0);
        next(cnt + (i * i), x, y, i);
        fill(x, y, i, 1);
        type[i - 1]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
            if (map[i][j])
                total++;
        }
    }

    if (total <= 3) {
        cout << total;
        return 0;
    }

    go(0, 0, 0);

    if (ans == INF) {
        cout << -1;
    } else
        cout << ans << endl;

    return 0;
}