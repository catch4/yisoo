// 백준 1981번 배열에서 이동

/*
백트래킹 - 시간초과
풀이 실패
-> 힌트 참고하여 bfs +이분탐색

*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pi;
int n, map[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool v[101][101];
int low, hi;

bool bfs(int mid) {
	queue<pi> q;

	for (int val = low; val <= hi; val++) {
		memset(v, 1, sizeof(v));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] >= val && map[i][j] <= val + mid)
					v[i][j] = false;
			}
		}
		if (v[0][0]) {
			continue;
		}
		q.push({ 0,0 });
		v[0][0] = true;

		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			if (x == n - 1 && y == n - 1)return true;


			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny]) continue;
				q.push({ nx,ny });
				v[nx][ny] = true;
			}
		}

	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	low = 201, hi = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			low = min(low, map[i][j]);
			hi = max(hi, map[i][j]);
		}
	}

	int right = hi - low;
	int left = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (bfs(mid)) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << right + 1;

	return 0;
}