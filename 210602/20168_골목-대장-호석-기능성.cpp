// 백준 20168번 골목-대장-호석-기능성

// dfs + backtracking

#include <iostream>
#include <vector>
#define MAX 11

using namespace std;
typedef pair<int, int> pi;

int n, m, a, b, c;
vector<pi> adj[MAX];
bool v[MAX];
int answer = 1e9;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> a >> b >> c;

    int x, y, cost;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> cost;
        adj[x].push_back({ y, cost });
        adj[y].push_back({ x, cost });
    }
}

void dfs(int cur, int cost, int maxVal)
{
    if (cost > c)
        return;
    if (cur == b) {
        answer = min(maxVal, answer);
        return;
    }

    for (pi p : adj[cur]) {
        if (!v[p.first]) {
            v[p.first] = 1;
            dfs(p.first, cost + p.second, max(maxVal, p.second));
            v[p.first] = 0;
        }
    }
}

int main()
{
    input();
    dfs(a, 0, 0);
    if (answer == 1e9)
        cout << -1;
    else
        cout << answer;
    return 0;
}