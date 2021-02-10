// 백준 169472번 서울-지하철-2호선

/*
dfs + cycle 판단 + bfs

1. 모든 노드의 간선 개수가 2개이하면 모두 싸이클
=> 간선의 개수가 3개이상이면 지선이 있다!

2-1. 지선의 출발점 후보부터 dfs로 탐색하면서 만약에 자신으로 돌아오면 이는 순환선 => 돌아오면 이전 역(parent)을 역탐색해서 순환선 체크
2-2. 자신으로 돌아오지 않으면 이는 지선의 일부

3. 순환선에서 출발해서 지선까지 거리를 bfs


*/

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 3001

using namespace std;

int n;
vector<int> adj[MAX];
int dist[MAX], p[MAX];
bool v[MAX], isCycle, cycle[MAX];

// 2-1. 순환선일 경우 이전 역을 역탐색하면서 순환선임을 체크
void getCycle(int parent, int end)
{
    cycle[parent] = 1;

    if (parent == end)
        return;
    getCycle(p[parent], end);
}

void dfs(int start, int before, int node)
{
    v[node] = true;

    for (int to : adj[node]) {
        if (!v[to]) {
            p[to] = node;
            dfs(start, node, to);
        } else if (before != start && to == start) { // 이전 역이 시작점이 아닌데, 다음 역이 시작점이면 순환!
            isCycle = true;
            cycle[start] = 1;
            getCycle(node, start);
            return;
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    v[start] = 1;

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (int to : adj[from]) {
            if (v[to] || cycle[to])
                continue;

            q.push(to);
            v[to] = 1;
            dist[to] = dist[from] + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dist, -1, sizeof(dist));
    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() >= 3) {
            dfs(i, i, i);
        }
        if (isCycle)
            break;
        memset(p, 0, sizeof(p));
        memset(v, 0, sizeof(v));
    }

    // 이미 모든 노드가 순환선일 경우!
    if (!isCycle) {
        for (int i = 1; i <= n; i++) {
            cout << "0 ";
        }
        return 0;
    }

    for (int i = 1; i <= n; i++) {

        if (cycle[i]) {
            dist[i] = 0;
        }
    }

    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++) {
        if (cycle[i])
            bfs(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}