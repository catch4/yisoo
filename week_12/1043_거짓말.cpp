// 백준 1043번 거짓말

/*
나중에 들어도 들통남
=> 진실을 아는 사람과 같은 파티에만 있어도 진실을 아는 것과 같다!

1. 그래프 연결
2. bfs로 연결된 노드 확인
3. 속하는지 아닌지 확인
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
bool truth[51];
int p[51][51];	//파티 참석하는 사람의 번호
int person[51]; // 파티당 사람의 수
bool connect[51][51];
bool v[51];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	v[s] = true;

	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i = 1; i <=n; i++) {
			if (p != i && connect[p][i] && !v[i]) {
				q.push(i);
				v[i] = true;
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		int idx;
		cin >> idx;
		truth[idx] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> person[i];
		for (int j = 0; j < person[i]; j++) {
			cin >> p[i][j];
		}
	}
	if (num == 0) {
		cout << m;
		return 0;
	}
	// 1. 그래프 연결.
	for (int i = 0; i < m; i++) {
		sort(p[i], p[i] + person[i]);
		for (int j = 0; j < person[i]; j++) {
			for (int k = j + 1; k < person[i]; k++) {
				connect[p[i][j]][p[i][k]] = connect[p[i][k]][p[i][j]] = true;
			}
		}
	}

	// 2. bfs
	for (int i = 1; i <= n; i++) {
		if (truth[i])
			bfs(i);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool flag = true;
		for (int j = 0; j < person[i]; j++) {
			if (v[p[i][j]]) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}


	cout << ans;

	return 0;
}