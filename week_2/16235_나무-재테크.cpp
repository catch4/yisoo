#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

 // ���� 16235�� ���� ����ũ

using namespace std;

// 0. ���� � �������� ��� �����Ƿ� ���� � ������ ������ �;� �Ѵ�. => �켱���� ť(�ð� �ʰ�) => ���� �� �� �̿�.
// 0-0. ��ġ�� ���� ������ ��, �����ؼ� ���� ����.
// 1. ��/���� : �� ���鼭 ��� �԰� ���� 1 ����. ��� �������� dead�� ����/2 �߰�. 
// 2. ����/�ܿ� : ���� Ȯ���ؼ� �ֺ� ���� �ɱ�
// 3. K�� �ݺ�.
// 4. ��ü ���� ���鼭 ���� ������ Ȯ��.


int n, m, k;
int A[11][11];
int map[11][11];
vector<int> temp[11][11];
deque<int> tree[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// ��, ����
void ss(int r, int c) {
	deque<int> d = tree[r][c];
	deque<int> newTree;
	int dead = 0;
	while (!d.empty()) {
		int t = d.front();
		d.pop_front();

		if (t <= map[r][c]) {
			map[r][c] -= t;
			newTree.push_back(t + 1);
		}
		else {
			dead += t / 2;
		}
	}
	map[r][c] += dead;
	tree[r][c] = newTree;
	return;
}
// ����, �ܿ�
void fw(int r, int c) {
	deque<int> d = tree[r][c];
	while (!d.empty()) {
		int t = d.front();
		d.pop_front();
		if (t % 5 == 0) {
			for (int i = 0; i < 8; i++) {
				int nx = r + dx[i];
				int ny = c + dy[i];
				if (nx > 0 && nx <= n && ny>0 && ny<=n) {
					tree[nx][ny].push_front(1);
				}
			}
		}
	}
	map[r][c] += A[r][c];
	
	return;
}
// �ʱ� ���� ���̺� �����Ͽ� ���� ����.
void push() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(temp[i][j].begin(), temp[i][j].end());
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < temp[i][j].size(); k++) {
				tree[i][j].push_back(temp[i][j][k]);
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];
	
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		temp[x][y].push_back(z);
	}
	// ����
	push();

	// map �ʱ�ȭ
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = 5;
	
	// k��
	while (k--) {
		// ��� ĭ���� ��,����
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				ss(i, j);
		// ����, �ܿ�
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				fw(i, j);
	}
	int answer = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			answer += tree[i][j].size();

	cout << answer;
	

	return 0;
}