#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

// ���� 1939 �߷�����.

using namespace std;

// 1. ���� Ư�� �߷� w���� Ŀ�� �Ѵ�.
// 1-1. bfs�� ���鼭 ���� w���� ������ �н�, Ŭ ��쿡�� Ȯ��
// 1-2. ���������� ���������� w ���� / �ƴϸ� �Ұ���
// 2. �̺�Ž������ ���� ū wã��.

vector<pair<int,int>> map[10001];
int n, m, depart, arrive;
bool v[10001];

// 1.
bool bfs(int w) {
	queue<int> q;
	memset(v, 0, sizeof(v));
	q.push(depart);
	v[depart] = true;

	while (!q.empty()) {
		int from = q.front();
		q.pop();
		for (int i = 0; i < map[from].size(); i++) {
			int to = map[from][i].first;
			int cost = map[from][i].second;
			// 1-1.
			if (cost >= w && !v[to]) {
				q.push(to);
				v[to] = true;
			}
		}
	}
	// 1-2.
	return v[arrive];
}

int main() {
	
	int answer = 0;
	cin >> n >> m;
	int w = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		w = max(w, c);
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	cin >> depart >> arrive;

	int low = 0, high = w;
	// 2.
	while (low <= high) {
		int mid = (low + high) / 2;
		if (bfs(mid)) {
			answer = max(answer,mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	
	cout << answer;

	return 0;
}