// 백준 4991번 로봇-청소기

#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pi;

int h, w;
char room[21][21];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<pi> dirty;
vector<vector<int>> sequence;
int dist[11][11];
pi start;
int visit[21][21];
bool check[11];
const int INF = 1e8;

void input()
{
    string str;
    for (int i = 0; i < h; i++) {
        cin >> str;
        for (int j = 0; j < w; j++) {
            room[i][j] = str[j];
            if (room[i][j] == '*')
                dirty.push_back({ i, j });
            else if (room[i][j] == 'o')
                start = { i, j };
        }
    }
}

int moveRobot(pi from, pi to)
{
    memset(visit, 0, sizeof(visit));
    queue<pi> q;

    visit[from.x][from.y] = 1;
    q.push(from);

    while (!q.empty()) {
        pi cur = q.front();
        q.pop();

        if (cur == to)
            return visit[cur.x][cur.y] - 1;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || visit[nx][ny] || room[nx][ny] == 'x')
                continue;
            visit[nx][ny] = visit[cur.x][cur.y] + 1;
            q.push({ nx, ny });
        }
    }
    return INF;
}

void prepareDistance()
{
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < dirty.size(); i++) {
        // between start and dirty
        dist[10][i] = dist[i][10] = moveRobot(start, dirty[i]);
        // between dirties
        for (int j = i + 1; j < dirty.size(); j++) {
            dist[i][j] = dist[j][i] = moveRobot(dirty[i], dirty[j]);
        }
    }
}

void generateSequence(vector<int>& arr)
{
    if (arr.size() == dirty.size()) {
        sequence.push_back(arr);
        return;
    }

    for (int i = 0; i < dirty.size(); i++) {
        if (!check[i]) {
            check[i] = 1;
            arr.push_back(i);
            generateSequence(arr);
            arr.pop_back();
            check[i] = false;
        }
    }
}

int calculateTotalDistance(vector<int> seq)
{
    int sum = dist[seq[0]][10];

    for (int i = 0; i < seq.size() - 1; i++) {
        sum += dist[seq[i]][seq[i + 1]];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        memset(room, 0, sizeof(room));
        dirty.clear();
        sequence.clear();

        input();
        vector<int> arr;
        generateSequence(arr); // n!
        prepareDistance(); // n^2

        int answer = INF;
        for (vector<int> seq : sequence) {
            int val = calculateTotalDistance(seq);
            answer = min(answer, val);
        }

        if (answer == INF)
            cout << "-1\n";
        else
            cout << answer << "\n";
    }

    return 0;
}