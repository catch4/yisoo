// 백준 3109번 빵집

/*
dfs로 확인.

*/

#include <iostream>

using namespace std;

int r, c;
char map[10001][501];

int dx[3] = { -1,0,1 };

bool go(int x, int y) {
	if (y == c - 1) 
		return true;
	
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		if (nx < 0 || nx >= r) continue;
		if (map[nx][y + 1] == 'x') continue;
		map[nx][y + 1] = 'x';
		if (go(nx, y + 1))
			return true;
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) 
			cin >> map[i][j];
	int ans = 0;
	
	for (int i = 0; i < r; i++) {
		if (go(i, 0))
			ans++;
	}
	cout << ans;
	return 0;
}