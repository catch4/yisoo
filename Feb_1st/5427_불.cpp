// 백준 5427번 불

#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define x first
#define y second

using namespace std;
typedef pair<int, int> pi;

int tc, m, n;
char map[1001][1001];
bool v[1001][1001];
vector<pi> fire;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
pi start;

int escape()
{
    queue<pi> spread;
    queue<pi> run;
    run.push(start);
    for (pi f : fire)
        spread.push(f);

    v[start.x][start.y] = 1;

    int time = 0;
    while (!run.empty()) {

        int fs = spread.size();
        for (int i = 0; i < fs; i++) {
            pi now = spread.front();

            spread.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i], ny = now.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#' || map[nx][ny] == '*')
                    continue;
                spread.push({ nx, ny });
                map[nx][ny] = '*';
            }
        }

        int rs = run.size();
        for (int i = 0; i < rs; i++) {
            pi from = run.front();

            run.pop();
            for (int i = 0; i < 4; i++) {
                int nx = from.x + dx[i], ny = from.y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    return time + 1;
                }
                if (map[nx][ny] == '#' || map[nx][ny] == '*' || v[nx][ny])
                    continue;
                run.push({ nx, ny });
                v[nx][ny] = 1;
            }
        }
        time++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> tc;

    while (tc--) {

        fire.clear();
        memset(v, 0, sizeof(v));
        cin >> m >> n;
        string str;

        for (int i = 0; i < n; i++) {
            cin >> str;
            for (int j = 0; j < m; j++) {
                map[i][j] = str[j];
                if (map[i][j] == '@')
                    start = { i, j };
                if (map[i][j] == '*')
                    fire.push_back({ i, j });
            }
        }

        int ret = escape();
        if (ret != -1) {
            cout << ret << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}