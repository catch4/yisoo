// 백준 16954번 움직이는-미로-탈출

// 미로를 미리 다 움직인 다음에 bfs로 확인.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct pos {
    int x, y, cnt;
};

char map[8][8][10];
bool v[8][8];
int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    for (int i = 0; i < 8; i++) {
        cin >> str;
        for (int j = 0; j < 8; j++) {
            map[i][j][0] = str[j];
        }
    }
}

void move_wall()
{
    for (int k = 0; k < 9; k++) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                map[i][j][k + 1] = map[i][j][k];
            }
        }
        for (int i = 7; i > 0; i--) {
            for (int j = 0; j < 8; j++) {
                map[i][j][k + 1] = map[i - 1][j][k + 1] == '#' ? '#' : '.';
            }
        }
        for (int i = 0; i < 8; i++) {
            map[0][i][k + 1] = '.';
        }
    }
}

int solve()
{
    queue<pos> q;
    pos start = { 7, 0, 0 };

    q.push({ start });
    while (!q.empty()) {
        pos now = q.front();
        q.pop();
        if (now.x == 0 && now.y == 7)
            return 1;
        if (map[now.x][now.y][now.cnt] == '#')
            continue;

        for (int i = 0; i < 9; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];

            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || map[nx][ny][now.cnt] == '#')
                continue;
            q.push({ nx, ny, now.cnt + 1 });
        }
    }
    return 0;
}

int main()
{
    input();
    move_wall();
    cout << solve();

    return 0;
}