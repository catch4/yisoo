// 백준 16197번 두-동전

// bfs
// 움직임의 경우를 고려한다.

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

typedef struct Loc {
    int x1, y1;
    int x2, y2;
    int cnt;
} loc;

int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char map[21][21];

vector<pi> coin;

void input()
{
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j];
            if (str[j] == 'o')
                coin.push_back({ i, j });
        }
    }
}

bool isRange(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int solve()
{
    queue<loc> q;

    q.push({ coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0 });

    while (!q.empty()) {
        loc cur = q.front();
        q.pop();

        // 방문 체크 대신 횟수 제한
        if (cur.cnt >= 10)
            continue;

        for (int i = 0; i < 4; i++) {
            int nx1 = cur.x1 + dx[i], nx2 = cur.x2 + dx[i], ny1 = cur.y1 + dy[i], ny2 = cur.y2 + dy[i];

            loc nxt = { nx1, ny1, nx2, ny2, cur.cnt + 1 };

            bool r1 = isRange(nx1, ny1);
            bool r2 = isRange(nx2, ny2);

            // 1. 범위 안이면서 벽이 아님 => 고
            // 2. 범위 안이면서 벽임 => 현재
            if (r1 && r2) {
                if (map[nx1][ny1] == '#') {
                    nxt.x1 = cur.x1, nxt.y1 = cur.y1;
                }
                if (map[nx2][ny2] == '#') {
                    nxt.x2 = cur.x2, nxt.y2 = cur.y2;
                }
                q.push(nxt);
            } else if (!r1 && !r2) { // 둘 다 범위 밖
                continue;
            } else {
                return nxt.cnt;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << solve();
    return 0;
}