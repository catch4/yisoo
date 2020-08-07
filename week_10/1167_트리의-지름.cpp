// ���� 1167�� Ʈ���� ����

/*
nlogn ���� �ذ��ؾ� �Ѵ�.

�������
1.��Ʈ���� ���������� �Ÿ�
bfs

2. ���������� �Ÿ�.
��Ʈ���� ���� �� ������ �ٽ� �����Ͽ� ���� �� ��带 ã��.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define SIZE 100001

using namespace std;

typedef pair<int, int> pi;

int v;
int dist[SIZE];
vector<pi> node[SIZE];

int answer;


void bfs(int start) {
	queue<int> q;
	memset(dist, -1, sizeof(dist));

	dist[start] = 0;
	q.push(start);
	
	while (!q.empty()) {
		int parent = q.front();
		q.pop();

		int base = dist[parent];
		
		for (int i = 0; i < node[parent].size(); i++) {
			int child = node[parent][i].first;
			int cost = node[parent][i].second;
			if (dist[child] != -1) continue;
			dist[child] = base + cost;
			q.push(child);
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> v;
	int idx;
	for (int i = 0; i < v; i++) {
		cin >> idx;
		int a, b;
		cin >> a;
		while (a != -1) {
			cin >> b;
			node[idx].push_back({ a,b });
			cin >> a;
		}
	}
	int most = 1;
	bfs(most);
	most = max_element(dist, dist + v + 1) - dist;
	answer = max(answer, dist[most]);
	bfs(most);
	answer = max(answer, *max_element(dist, dist + v+1));
	cout << answer;

	return 0;
}

