// 백준 1948번 임계경로

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001
using namespace std;
typedef pair<int, int> pi;

int n, m, s, e;
vector<pi> adj[MAX], revAdj[MAX];
int time[MAX], p[MAX];
int cnt;
bool v[MAX];

void tpsort()
{
    queue<int> q;

    q.push(s);

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (pi next : adj[from]) {
            int to = next.first;
            int cost = next.second;

            time[to] = max(time[to], time[from] + cost);
            p[to]--;

            if (p[to] == 0) {
                q.push(to);
            }
        }
    }
}

void go()
{
    queue<int> q;

    q.push(e);
    v[e] = 1;

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (pi next : revAdj[from]) {
            int to = next.first;
            int cost = next.second;

            if (cost == time[from] - time[to]) {
                cnt++;
                if (!v[to]) {
                    v[to] = 1;
                    q.push(to);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        revAdj[b].push_back({ a, c });
        p[b]++;
    }
    cin >> s >> e;

    tpsort();

    go();

    cout << time[e] << "\n"
         << cnt << "\n";

    return 0;
}