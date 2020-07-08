#include <iostream>

// ���� 15684�� ��ٸ� ����

using namespace std;

// 1. ������ ��ٸ��� ��� ����
// 1-1. ��ٸ��� ������ ���� �������� ���־� �ߺ��� ���� �� �ִ�.
// 1-2. ���� ���� �дٸ� ������ �� �ຸ�ٴ� �Ʒ� �࿡ ���д�. ���� �״�� Ȯ��.
// 2. ��ٸ� ��� Ȯ��


int n, m, h;
int ladder[31][11];
int answer;

// 2.
bool check() {
	for (int i = 1; i <= n; i++) {
		int y = i;
		for (int j = 1; j <= h; j++) {
			if (ladder[j][y] == 1)
				y++;
			else if (ladder[j][y] == 0) {
				if(ladder[j][y-1] == 1)
					y--;
			}
		}
		if(y !=i) return false;
	}
	return true;
}
// 1. ������ �������� �θ� ������ ���� Ȯ��
void go(int x, int cnt) {
	if (check()) {
		answer = answer > cnt ? cnt : answer;
		return;
	}
	if (cnt == 3)
		return;
	for (int i = x; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[i][j-1] == 0 && ladder[i][j] == 0 && ladder[i][j + 1] == 0) {
				ladder[i][j] = 1;
				go(i,cnt + 1);
				ladder[i][j] = 0;
			}
		}
	}
	return;
}


int main() {
	cin >> n >> m >> h;
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= n; j++) {
			ladder[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x][y] = 1;
	}
	answer = 4;
	go(1,0);
	if (answer == 4) cout << "-1";
	else cout << answer;
	return 0;
}