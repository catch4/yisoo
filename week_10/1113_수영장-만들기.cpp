// ���� 1113�� ������ �����

/*
1. �����ڸ��� ������ x
2. ���� 1���� 8���� �ϳ��� Ȯ��
2-1. ���� n�� ĭ�� ��������� ���� ĭ�� bfs�� Ȯ��
2-2. ���� n�� ĭ�� �����ڸ��� �ش��Ѵٸ� �̴� �Ұ����ϹǷ� ���󺹱� �� return
2-3. ���� n�� ĭ�� ��� ���ǿ� �����Ѵٸ� �ش� ĭ 1���� + ĭ ���� Ȯ��.

*/

#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int n,m;
int swim[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool v[50][50];
int map[50][50];

int bfs(int x, int y, int val) {

	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) map[i][j] = swim[i][j];
	queue<pi> q;
	q.push({ x,y });
	v[x][y] = true;
	map[x][y] = swim[x][y] + 1;
	int ret = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i], ny = b + dy[i];
			if (v[nx][ny] || swim[nx][ny] > val) continue;
			if (nx <= 0 || ny <= 0 || nx >= n - 1 || ny >= m - 1 || swim[nx][ny] < val) {
				return 0;
			}	
			q.push({ nx,ny });
			v[nx][ny] = true;
			map[nx][ny] = swim[nx][ny] + 1;
			ret++;
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) swim[i][j] = map[i][j];
	return ret;
}


int solve() {
	if (n <= 2 || m <= 2) return 0;
	int ret = 0;
	for (int val = 1; val < 9; val++) {		
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (val == swim[i][j]) {
					ret+= bfs(i, j, val);
				}
			}
		}
	}

	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			swim[i][j] = str[j] - '0';
		}
	}
	int ret = solve();
	cout << ret;
	return 0;
}
