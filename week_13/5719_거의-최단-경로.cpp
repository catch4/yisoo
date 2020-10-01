// 백준 5719번 거의 최단 경로

/*
접근 :
0. 보자마자 다익스트라 확인
1. 최단 경로에 포함되지 않는 경로로 다시 최단 경로를 만들 때 거의 최단 경로가 된다.
=> 최단 경로를 삭제하고 다시 다익스트라하면 된다.
2. 다익스트라 -> 최단 경로 삭제 -> 다익스트라 어게인

* 10.01 
재채점으로 인해 큐 -> 재귀 수정
*/

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
int n, m, s, d;
vector<pi> gps[500];
vector<int> ans[500];
const int INF = 987654321;

// mode가 켜져있으면 최단, 아니면 거의 최단 경로
int dji(int mode)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dist(n, INF);

    dist[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (dist[from] < cost)
            continue;
        int size = gps[from].size();
        for (int i = 0; i < size; i++) {
            int to = gps[from][i].first;
            int nextCost = gps[from][i].second;

            if (nextCost == INF || to == s)
                continue;

            if (dist[to] > dist[from] + nextCost) {
                dist[to] = dist[from] + nextCost;
                pq.push({ dist[to], to });
                if (mode) {
                    ans[to].clear();
                    ans[to].push_back(from);
                }
            } else if (mode && dist[to] == dist[from] + nextCost) {
                ans[to].push_back(from);
            }
        }
    }
    if (dist[d] == INF)
        return -1;
    return dist[d];
}

void remove(int dst)
{
    for (int i = 0; i < ans[dst].size(); i++) {
        int pre = ans[dst][i]; // 이전 경로
        for (int j = 0; j < gps[pre].size(); j++)
            if (gps[pre][j].first == dst) // 출발지가 pre이고 목적지가 dst인 곳 삭제
            {
                gps[pre][j].second = INF;
                break;
            }
        remove(ans[dst][i]);
    }
    ans[dst].clear();
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true) {

        cin >> n >> m;
        if (n == 0)
            break;
        cin >> s >> d;

        for (int i = 0; i < 500; i++) {
            gps[i].clear();
            ans[i].clear();
        }
        int u, v, p;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            gps[u].push_back({ v, p });
        }
        dji(1);
        remove(d);
        cout << dji(0) << "\n";
    }
    return 0;
}