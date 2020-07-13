#include <iostream>
#include <queue>
#include <cstring>
#include <string>
// 백준 4485 녹색 옷 입은 애가 젤다지?

using namespace std;

// 노드간 최소비용? => 다익스트라.

typedef pair<int, vector<int>> pi;
const int INF = 987654321;
vector<int> ans;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0, -1,1 };

int dji(vector<vector<int>> board, int n) {
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	vector<vector<int>> dist(n, vector<int>(n, INF));

	pq.push({ board[0][0],{0,0} });
	dist[0][0] = board[0][0];

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second[0], y = pq.top().second[1];
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (dist[nx][ny] > cost + board[nx][ny]) {
				dist[nx][ny] = cost + board[nx][ny];
				pq.push({ dist[nx][ny], {nx,ny} });
			}
		}
	}
	return dist[n - 1][n - 1];
}


int main() {
	int tc = 0;
	while (true) {
		tc++;
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		vector<vector<int>> board(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		cout << "Problem "<<tc<< ": " << dji(board, n) << endl;
	}
	return 0;
}