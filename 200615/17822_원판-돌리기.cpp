#include <iostream>
#include <vector>
#include <deque>
// ���� 17822�� ���� ������

using namespace std;

// ������ ���� �迭�� �����س��� �������� �ð��� ���� �ɸ� �� ����. => deque�� �̿��� �ð� ���̱�.
// deque�� ����Ͽ� �� �ڸ� ���� ������ ���� ������.
// ȸ�� ��ɾ ���� ������ ������ �� ���ִ� ���� ó���� �ؾ� �Ѵ�. 

int n, m, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// ȸ��.
void rotate(deque<deque<int>>& circle, int x, int d, int k) {
		// ȸ���� �� ���� �ϴ� ������ ������.
		int direction = k > m - k ? 1 - d : d;
		int it = k > m - k ? m - k : k;

		if (direction) {	// �ݽð� ����
			for (int idx = x-1; idx < n; idx += x) {
				for (auto i = 0; i < it; i++) {
					circle[idx].push_back(circle[idx][0]);
					circle[idx].pop_front();
				}
			}
		}
		else {			// �ð� ����
			for (int idx = x - 1; idx < n; idx += x) {
				for (auto i = 0; i < it; i++) {
					circle[idx].push_front(circle[idx][m-1]);
					circle[idx].pop_back();
				}
			}
		}
		
		return;
}

// ������ �� ���ְų� ��� ���ϱ�.
deque<deque<int>> check(deque<deque<int>> circle) {
	int cnt = 0;
	int sum = 0;
	double x = 0;
	// ������ ���� ���� �迭.
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
				// ���� �����Ѵٸ�
				if (circle[nx][ny] == circle[i][j]) {
					cnt++;
					new_check[nx][ny] = new_check[i][j] = -1;
				}
			}
			// ������ ���� ���� ���� ����Ͽ� ��� ���ϱ�.
			if (new_check[i][j] != -1) {
				sum += new_check[i][j];
				x++;
			}
			
		}
	}
	// ������ ���� �־��ٸ�
	if (cnt != 0) {
		return new_check;	// ������ �� ���� �迭 ��ȯ
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