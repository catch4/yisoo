// ���� 14890�� ����

// 1. �ùķ��̼� ����. 
// 2. �� 2N������ Ȯ���ϸ� �ǹǷ� �ð���ü�� ���� �ɸ��� �ʴ´�.


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, l;
int map[100][100];

bool count(int x, int y) {
	vector<bool>v(n, 0);
	if (y == -1) {	// �� Ȯ��
		for (int i = 0; i < n-1; i++) {
			if (map[x][i] == map[x][i + 1])	// ���� ������ �н�
				continue;
			if (abs(map[x][i] - map[x][i + 1]) > 1)	// ���� ���� 2�̻� false
				return false;
			
			// �������� ���� ���������� ���� ���ϱ�.
			int cnt = map[x][i] < map[x][i + 1] ? -1 : 1;
			int ny = cnt == -1 ? i : i + 1;
			int idx = ny, size = 0;
			
			while (idx >= 0 && idx < n && map[x][ny] == map[x][idx] && !v[idx] && size != l) {
				v[idx] = 1;
				idx += cnt;
				size++;
			}
			if (size != l)
				return false;
		}
		return true;
	}
	else{	// �� Ȯ��
		for (int i = 0; i < n - 1; i++) {
			if (map[i][y] == map[i+1][y])
				continue;
			if (abs(map[i][y] - map[i+1][y]) > 1)
				return false;
			
			int cnt = map[i][y] < map[i+1][y] ? -1 : 1;
			int nx = cnt == -1 ? i : i + 1;
			int idx = nx, size = 0;

			while (idx >= 0 && idx < n && map[nx][y] == map[idx][y] && !v[idx] && size != l) {
				v[idx] = 1;
				idx += cnt;
				size++;
			}
			if (size != l) return false;
		}
		return true;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (count(i, -1)) {
			ans++;
		}
		if (count(-1, i)) {
			ans++;
		}
			
	}

	cout << ans;
	return 0;
}