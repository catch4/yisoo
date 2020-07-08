#include <iostream>
#include <vector>
#include <deque>
// 백준 17822번 원판 돌리기

using namespace std;

// 원판의 수를 배열에 저장해놓고 돌리려니 시간이 오래 걸릴 것 같다. => deque를 이용해 시간 줄이기.
// deque을 사용하여 앞 뒤를 빼고 넣으며 원판 돌리기.
// 회전 명령어가 끝날 때마다 인접한 수 없애는 등의 처리를 해야 한다. 

int n, m, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 회전.
void rotate(deque<deque<int>>& circle, int x, int d, int k) {
		// 회전을 더 적게 하는 쪽으로 돌리기.
		int direction = k > m - k ? 1 - d : d;
		int it = k > m - k ? m - k : k;

		if (direction) {	// 반시계 방향
			for (int idx = x-1; idx < n; idx += x) {
				for (auto i = 0; i < it; i++) {
					circle[idx].push_back(circle[idx][0]);
					circle[idx].pop_front();
				}
			}
		}
		else {			// 시계 방향
			for (int idx = x - 1; idx < n; idx += x) {
				for (auto i = 0; i < it; i++) {
					circle[idx].push_front(circle[idx][m-1]);
					circle[idx].pop_back();
				}
			}
		}
		
		return;
}

// 인접한 수 없애거나 평균 구하기.
deque<deque<int>> check(deque<deque<int>> circle) {
	int cnt = 0;
	int sum = 0;
	double x = 0;
	// 인접한 수를 없앤 배열.
	deque<deque<int>> new_check = circle;

	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < m; j++) {
			if (circle[i][j] == -1)
				continue;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n)
					continue;
				if (ny == -1) ny = m - 1;
				else if (ny == m) ny = 0;
				// 만약 인접한다면
				if (circle[nx][ny] == circle[i][j]) {
					cnt++;
					new_check[nx][ny] = new_check[i][j] = -1;
				}
			}
			// 인접한 수가 없는 것을 고려하여 평균 구하기.
			if (new_check[i][j] != -1) {
				sum += new_check[i][j];
				x++;
			}
			
		}
	}
	// 인접한 수가 있었다면
	if (cnt != 0) {
		return new_check;	// 인접한 수 없앤 배열 반환
	}
		
	double avg = (double)sum / x;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (new_check[i][j] == -1)
				continue;
			if (new_check[i][j] > avg)
				new_check[i][j] -= 1;
			else if(new_check[i][j]<avg)
				new_check[i][j] += 1;
		}
	}
	return new_check;
}

int main() {
	cin >> n >> m >> t;

	deque<deque<int>> circle(n, deque<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> circle[i][j];

	vector<vector<int>> cmd(t, vector<int>(3));
	for (int i = 0; i < t; i++)
		cin >> cmd[i][0] >> cmd[i][1] >> cmd[i][2];

	
	for (vector<int> v : cmd) {
		rotate(circle, v[0], v[1], v[2]);
		circle = check(circle);
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (circle[i][j] == -1)
				continue;
			answer += circle[i][j];
		}
	}
	cout << answer << endl;
	return 0;
}