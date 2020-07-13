#include <iostream>
#include <stack>
#include <algorithm>

// ���� 14503�� �κ� û�ұ�

using namespace std;

int b[50][50];
int N, M, r, c, direction;
int answer;
int dx[4] = { 0, -1, 0, 1 };	// ��, ��, ��, �� (��,��,��,�� �� ����)
int dy[4] = { -1, 0, 1, 0 };
int rx[4] = { 1, 0 , -1, 0 };
int ry[4] = { 0, -1, 0, 1 };


void dfs(int x, int y, int d) {
	//1. û��
	if (b[x][y] == 0) {
		answer++;
		b[x][y] = 2;
	}
	//2. ���� Ž��
	int w = d;
	int nx = x + dx[w];
	int ny = y + dy[w];
	int time = 4;

	// ������ û�Ҹ� �� �ߴ� �� Ȯ��, �� ����ٸ� ���� �������� ������  / �ݺ�
	while (nx <= 0 || nx >= N - 1 || ny <= 0 || ny >= M - 1 || b[nx][ny] != 0) {
		time--;
		if (w == 0) w = 3;
		else w--;
		nx = x + dx[w];
		ny = y + dy[w];
		if (time== 0)
			break;
	}

	// ���� ������.
	if (w == 0) w = 3;
	else w--;

	//a. ���� û�� �� ������
	//b. 4���� �� û�� ���� ���� ���� ��
	if (time > 0) {
		dfs(nx, ny, w);
	}
	else{	// ����
		nx = x + rx[d]; 
		ny = y + ry[d];
		//c. ���� ���ٸ�
		if (b[nx][ny] != 1)
			dfs(nx, ny, d);
		else // ���̶��
			return;
	}
	return;

}


int main() {
	cin >> N >> M;
	cin >> r >> c >> direction;
	answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> b[i][j];
		}
	}
	dfs(r, c, direction);
	cout << answer;
	return 0;
}