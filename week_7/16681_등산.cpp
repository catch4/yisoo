// ���� 16681�� ���

/*
1������ ��ǥ������ �Ÿ�, n������ ��ǥ������ �Ÿ��� ���Ǵ� ü��
��ǥ ���� * e�� ����.
���ͽ�Ʈ��� �Ÿ� ���

�������� 
���ͽ�Ʈ�� ��� �� top�� �ִ� ���� ������ ������ ũ�ٸ� �Ѿ�� ��(line 49) ���� ��� �ð��ʰ�. �̰ɷ� 1�ð� ���̻� ����

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

#define SIZE 100001

using namespace std;

typedef pair<int, int> pi;
typedef pair<long long, long long> pp;

int n, m, d, e;
long long h[SIZE];

vector<pi> way[SIZE];
long long ret = LLONG_MIN;
long long dist[2][SIZE];
const long long INF = LLONG_MAX;

void go(int now) {
	for (int i = 0; i <= n; i++) {
		dist[now][i] = INF;
	}
	int start = now == 0 ? 1 : n;

	priority_queue<pp, vector<pp>, greater<pp>>pq;

	pq.push({ 0,start });
	dist[now][start] = 0;
	while (!pq.empty()) {
		long long cost = pq.top().first;
		long long from = pq.top().second;
		pq.pop();

		if (dist[now][from] < cost) continue;

		for (auto p : way[from]) {
			int to = p.first;
			int distance = p.second;

			if ((h[to] > h[from]) && dist[now][to] > cost + distance) {
				dist[now][to] = cost + distance;
				pq.push({ dist[now][to],to });
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m >> d >> e;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		way[x].push_back({ y,c });
		way[y].push_back({ x,c });
	}
	
	// ������ 1��
	go(0); 
	// ������ n��
	go(1);

	for (int i = 2; i < n; i++) {
		if (dist[0][i] == INF || dist[1][i] == INF) continue;
		long long power = dist[0][i] + dist[1][i];
		long long temp = h[i] * e - power * d;
		ret = max(ret , temp);
	}

	if (ret == LLONG_MIN)
		cout << "Impossible";
	else
		cout << ret;

	return 0;
}