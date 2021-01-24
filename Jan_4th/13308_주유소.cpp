// 백준 13308번 주유소

// 최소가격까진 생각났으나 2차원 배열을 활용하지 못해 풀이 참고 = fail

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<ll, pi> pl;

int n, m;
ll price[2501];
vector<pi> adj[2501];
bool dp[2501][2501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> price[i];

    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    priority_queue<pl, vector<pl>, greater<pl>> pq;

    pq.push({ 0, { 1, price[1] } });

    while (!pq.empty()) {
        ll cost = pq.top().first;
        ll from = pq.top().second.first;
        ll minPrice = pq.top().second.second;

        pq.pop();

        if (dp[from][minPrice])
            continue;
        dp[from][minPrice] = 1;
        if (from == n) {
            cout << cost;
            return 0;
        }

        for (pi p : adj[from]) {
            ll minVal = min(price[p.first], minPrice);
            if (dp[p.first][minVal])
                continue;

            pq.push({ cost + minPrice * p.second, { p.first, minVal } });
        }
    }

    return 0;
}