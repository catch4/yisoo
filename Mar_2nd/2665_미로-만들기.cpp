// 백준 2665번 미로-만들기

// 간단한 bfs 문제

// 문제 아이디어 : 방을 도달하는데 최소 거치는 문의 개수 저장

#include <iostream>
#include <queue>
#include <string>
#define x first
#define y second

using namespace std;
typedef pair<int, int> pi;

int n, arr[51][51];
bool map[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs()
{
    queue<pi> q;
    q.push({ 0, 0 });

    // 1부터 한 이유는 방문 체크용
    arr[0][0] = 1;

    while (!q.empty()) {
        pi now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            // 다음 방이 흰 방이면 이전 방과 동일, 검은 방이면 방 개수 +1
            int val = arr[now.x][now.y] + (1 - map[nx][ny]);

            // 미방문 방
            if (!arr[nx][ny]) {
                arr[nx][ny] = val;
                q.push({ nx, ny });
            }
            // 방문한 방이면 최소값 저장
            else {
                if (arr[nx][ny] > val) {
                    arr[nx][ny] = val;
                    q.push({ nx, ny });
                }
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == '1')
                map[i][j] = 1;
        }
    }

    bfs();

    cout << arr[n - 1][n - 1] - 1;

    return 0;
}