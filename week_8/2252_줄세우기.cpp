// ���� 2252�� �� �����

/*
����� ����ġ�� �ִ� �׷����̹Ƿ� ���� ������ ���

Ǯ��: ���� ����
0. �迭 3���� Ǯ��
	�տ� ���� �л��� ��: p 
	�ڿ� ���� �л��� �迭 : arr
	�湮�ߴ��� Ȯ���ϴ� �迭 : v
1. a�� b�� �Է¹޾� p[b] ����, arr[a]�� b �߰�
2. p[i]�� 0�� ��� ť�� push
3. ����� ������ ����.
4. ����Ǿ� �ִ� ����� p���� 0�� �ȴٸ� ť�� push

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int p[32001];
vector<int> arr[32001];
bool v[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	// 1.
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		p[b]++;
		arr[a].push_back(b);
	}
	queue<int> q;
	// 2.
	for (int i = 1; i <= n; i++) {
		if (p[i] == 0) {
			q.push(i);
			v[i] = true;
		}
			
	}
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		cout << from << " ";
		for (int i = 0; i < arr[from].size(); i++) {
			int to = arr[from][i];
			p[to]--;	// 3.
			// 4.
			if (p[to] == 0 && !v[to]) {
				q.push(to);
				v[to] = true;
			}
		}
	}

	return 0;
}