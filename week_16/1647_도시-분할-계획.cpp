// 백준 1647번 도시 분할 계획

/*
MST 만든 후 최대값 삭제
프림 알고리즘 사용
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<pi> adj[100001];
bool v[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    int sum = 0;
    int maxVal = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int start;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() != 0) {
            start = i;
            break;
        }
    }
    v[start] = 1;
    int cnt = 1;
    for (int i = 0; i < adj[start].size(); i++) {
        pq.push(adj[start][i]);
    }
    while (!pq.empty()) {
        int cost = pq.top().first;
        int next = pq.top().second;
        pq.pop();
        if (v[next])
            continue;
        v[next] = 1;
        sum += cost;
        maxVal = max(maxVal, cost);
        if (++cnt == n)
            break;
        for (int i = 0; i < adj[next].size(); i++) {
            pq.push(adj[next][i]);
        }
    }
    cout << sum - maxVal;
    return 0;
}