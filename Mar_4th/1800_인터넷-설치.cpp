// 백준 1800번 인터넷-설치

// 풀이 실패

// 이분 탐색 + 다익스트라 (다익스트라도 K개 제한이라 0,1으로 풀어야 한다)
// 1939 중량제한과 유사한 문제.

#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001

using namespace std;

typedef pair<int, int> pi;

int n, p, k;
vector<pi> adj[MAX];
const int INF = 1e9;
int dist[MAX];

void input()
{
    cin >> n >> p >> k;

    int a, b, c;
    for (int i = 0; i < p; i++) {
        cin >> a >> b >> c;

        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
}

void init()
{
    for (int i = 0; i < MAX; i++)
        dist[i] = INF;
}

bool dji(int mid)
{
    init();
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        for (pi p : adj[from]) {
            int nc = cost + (p.second > mid);
            int to = p.first;
            if (dist[to] > nc) {
                dist[to] = nc;
                pq.push({ nc, to });
            }
        }
    }
    return dist[n] <= k;
}

int solve()
{
    int l = 0, r = 1e7;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (dji(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();
    cout << solve();

    return 0;
}