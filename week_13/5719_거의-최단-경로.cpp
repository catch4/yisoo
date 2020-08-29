// ���� 5719�� ���� �ִ� ��� 

/*
���� :
0. ���ڸ��� ���ͽ�Ʈ�� Ȯ��
1. �ִ� ��ο� ���Ե��� �ʴ� ��η� �ٽ� �ִ� ��θ� ���� �� ���� �ִ� ��ΰ� �ȴ�.
=> �ִ� ��θ� �����ϰ� �ٽ� ���ͽ�Ʈ���ϸ� �ȴ�.
2. ���ͽ�Ʈ�� -> �ִ� ��� ���� -> ���ͽ�Ʈ�� �����



*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
int n, m, s, d;

vector<pi> gps[501];
vector<int> ans[501];
const int INF = 987654321;

// mode�� ���������� �ִ�, �ƴϸ� ���� �ִ� ���
int dji(int mode) {	
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	vector<int> dist(n, INF);
	
	dist[s] = 0;
	pq.push({ 0,s });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (dist[from] < cost) continue;

		for (int i = 0; i < gps[from].size(); i++) {
			int to = gps[from][i].first;
			int nextCost = gps[from][i].second;
			
			if (nextCost == INF || to == s) continue;
			
			if (dist[to] > dist[from] + nextCost) {
				dist[to] = dist[from] + nextCost;
				pq.push({ dist[to], to });
				if (mode) {
					ans[to].clear();
					ans[to].push_back(from);
				}
			}
			else if (mode && dist[to] == dist[from] + nextCost) {
				ans[to].push_back(from);
			}
		}
	}
	if (dist[d] == INF)
		return -1;
	return dist[d];

}

void remove(){
	queue<int> q;
	q.push(d);

	while (!q.empty()) {
		int from = q.front();
		q.pop();

		for (int i = 0; i < ans[from].size(); i++) {
			int to = ans[from][i];
			
			for (int j = 0; j < gps[to].size(); j++) {
				if (gps[to][j].first == from) {
					gps[to][j].second = INF;
				}
			}
			q.push(to);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> n >> m;
		if (n == 0)
			break;
		cin >> s >> d;

		for (int i = 0; i < n; i++) {
			gps[i].clear();
			ans[i].clear();
		}
		int u, v, p;
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> p;
			gps[u].push_back({ v,p });
		}
		dji(1);
		remove();
		cout << dji(0) << "\n";

	}
	return 0;
}