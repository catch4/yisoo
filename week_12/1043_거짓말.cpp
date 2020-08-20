// ���� 1043�� ������

/*
���߿� �� ���볲
=> ������ �ƴ� ����� ���� ��Ƽ���� �־ ������ �ƴ� �Ͱ� ����!

1. �׷��� ����
2. bfs�� ����� ��� Ȯ��
3. ���ϴ��� �ƴ��� Ȯ��
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
bool truth[51];
int p[51][51];	//��Ƽ �����ϴ� ����� ��ȣ
int person[51]; // ��Ƽ�� ����� ��
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
	// 1. �׷��� ����.
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