// 백준 14558번 Line-Friends(Small)

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX 301

using namespace std;

struct Line {
    int start, end, num;
    bool operator<(const Line& line)
    {
        if (start == line.start)
            return end > line.end;
        return start < line.start;
    }
};

int dist[MAX][MAX];
Line arr[MAX];
int n, q, s, e;
const int INF = 1e9;

void lineInput()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s >> e;
        arr[i] = { s, e, i };
    }
}

void connectFriends()
{
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = arr[i].num;
            int y = arr[j].num;
            if (dist[x][y] == 1)
                continue;
            if (arr[i].end < arr[j].start)
                break;

            dist[x][y] = dist[y][x] = 1;
        }
    }
}

void floyd()
{

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void questionInput()
{
    cin >> q;
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << dist[a][b] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lineInput();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = INF;
    connectFriends();
    floyd();
    questionInput();

    return 0;
}