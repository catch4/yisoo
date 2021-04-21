// 백준 1162번 도로포장

#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

struct node {
    ll idx, cost, cnt;

    bool operator<(const node c) const
    {
        return cost > c.cost;
    }
};

int n, m, k;
vector<pi> adj[MAX];
ll dist[MAX][21];

void input()
{
    cin >> n >> m >> k;

    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
}

ll dji()
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 21; j++) {
            dist[i][j] = 5e10 + 1;
        }
    }
    priority_queue<node> pq;
    pq.push({ 1, 0, 0 });
    dist[1][0] = 0;

    while (!pq.empty()) {
        node cur = pq.top();
        pq.pop();

        ll now = cur.idx;
        ll cnt = cur.cnt;
        ll cost = cur.cost;

        if (cost > dist[now][cnt])
            continue;
        for (pi p : adj[now]) {
            ll nCost = cost + p.second;
            ll to = p.first;

            if (dist[to][cnt] > nCost) {
                dist[to][cnt] = nCost;
                pq.push({ to, nCost, cnt });
            }

            if (cnt < k && dist[to][cnt + 1] > cost) {
                dist[to][cnt + 1] = cost;
                pq.push({ to, cost, cnt + 1 });
            }
        }
    }
    ll ret = 5e10 + 1;
    for (int i = 0; i <= k; i++) {
        ret = min(ret, dist[n][i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    cout << dji();

    return 0;
}