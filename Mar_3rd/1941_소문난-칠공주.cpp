// 백준 1941번 소문난-칠공주

// 브루트포스로 25C7 구현 (그 중 도연이 4개이상은 제외)
// 7개가 연결되었는지 확인.

#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define LEN 5

using namespace std;
typedef pair<int, int> pi;

bool arr[LEN][LEN], v[LEN * LEN], check[LEN][LEN];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
map<pi, bool> visit;
int ans;

void input()
{
    for (int i = 0; i < LEN; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < LEN; j++) {
            if (str[j] == 'S')
                arr[i][j] = 1;
        }
    }
}

bool checkIfDasom(int idx)
{
    int x = idx / 5;
    int y = idx % 5;
    return arr[x][y];
}

pi convertToPi(int idx)
{
    return { idx / 5, idx % 5 };
}

bool isInRange(int x, int y)
{
    return (x >= 0 && x < LEN && y >= 0 && y < LEN);
}

bool isConnected(vector<int>& count)
{
    visit.clear();
    memset(check, 0, sizeof(check));
    for (auto idx : count) {
        pi pos = convertToPi(idx);
        visit[pos] = 1;
    }

    queue<pi> q;
    pi start = convertToPi(count[0]);
    q.push(start);
    check[start.first][start.second] = 1;
    int cnt = 0;
    while (!q.empty()) {
        pi now = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i], ny = now.second + dy[i];

            if (!isInRange(nx, ny) || !visit[{ nx, ny }] || check[nx][ny])
                continue;
            q.push({ nx, ny });
            check[nx][ny] = 1;
        }
    }

    return cnt == 7;
}

void go(int last, int y, int s, vector<int>& count)
{

    if (y >= 4)
        return;

    if (count.size() == 7) {

        bool ret = isConnected(count);
        if (ret) {
            ans++;
        }

        return;
    }

    for (int i = last + 1; i < LEN * LEN; i++) {
        if (!v[i]) {
            v[i] = true;
            count.push_back(i);
            if (checkIfDasom(i))
                go(i, y, s + 1, count);
            else
                go(i, y + 1, s, count);
            count.pop_back();
            v[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    vector<int> tmp;
    go(-1, 0, 0, tmp);

    cout << ans;
    return 0;
}