#include <iostream>
#include <string>
#include <vector>
#include <queue>

//���� 17244�� �Ƹ´ٿ��

using namespace std;

// 0. ���ͽ�Ʈ�� + ��Ʈ��ŷ�̶�� �����Ͽ���.
// 1. S ���� ������ x�� ���� e�� ���� �˰��� �ۼ� 
// 2. X�� ������ ��� ������ Ȯ���� ��� ���� Ȯ��
// 3. �� ��θ��� �ּ� �Ÿ��� �����ؼ� ���ͽ�Ʈ�� �ۼ�
// 4. ��� ������ Ȯ�������� ȣ��� �Լ����� ���� �̹� answer���� ũ�ٸ� �ʿ�����Ƿ� return�ؼ� ��Ʈ��ŷ �̿�.


char map[50][50];
int n, m;
pair<int, int> start, arrive;
vector<pair<int, int>> x;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int answer =987654321;

// 3. s�� ��� ��� e�� ��� ����. �� e-s������ �ּ� �Ÿ� ���.
int dfs(pair<int, int> s, pair<int, int>e) {
	queue<pair<int, int>> q;
	vector<vector<int>> dist(m, vector<int>(n, 987654321));
	q.push(s);
	dist[s.first][s.second] = 0;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || map[nx][ny] == '#')
				continue;
			if (dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return dist[e.first][e.second];
}

// 4. ��Ʈ��ŷ
void count(int cnt, int val, int last, vector<bool> check) {
	if (cnt == x.size()) {
		val += dfs(x[last], arrive);
		answer = answer > val ? val : answer;
		return;
	}
	// �̹� ���� ũ�ٸ� �� �� �ʿ� ����. 
	if (val > answer)
		return;
	// ����
	for (int i = 0; i < x.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			count(cnt + 1, val + dfs(x[last], x[i]), i, check);
			check[i] = false;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < n; j++) {
			map[i][j] = t[j];
			if (t[j] == 'S')
				start = { i,j };
			if (t[j] == 'E')
				arrive = { i,j };
			if (t[j] == 'X')
				x.push_back({ i,j });
		}
	}
	// S���� ù X����.
	for (int i = 0; i < x.size(); i++) {
		vector<bool> check(5, 0);
		int val = dfs(start, x[i]);
		check[i] = true;
		count(1, val, i, check);
	}
	// X�� ���ٸ� S���� E������ ����ϸ� �ȴ�.
	if (x.size() == 0) {
		answer = dfs(start, arrive);
	}
	cout << answer;
	return 0;
}