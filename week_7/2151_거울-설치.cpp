// ���� 2151�� �ſ� ��ġ

/*
ó���� �߸� �����ؼ� ����.

���ͽ�Ʈ��� ����ϰ� Ǯ���Ͽ���. 

ù ��° ������ �� ��° ������ �����ϴµ� ���Ǵ� �ſ��� ������ �Ÿ���� �Ǵ�.

1. �� ���� ��ǥ�� ����
2. ��ǥ�� ���󰡸� �Ÿ� ���.
2-1. ��ǥ��  . # �϶��� �� ������ �״�� ���� 
2-2. ! �϶��� ���� ���⿡�� �ٶ���� �� �� 3������ ����. ��,��, ���� => �̶��� ������ �Ÿ��� ���Ͽ� ���� ��츸 ť�� Ǫ��.
3. �湮 ��ǥ �߿� ���� ���� ���� ��ȯ.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, vector<int>> pp;

int n;
char home[50][50];
vector<pi> door;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int direction[4][2] = { {1,3},{2,0},{3,1},{0,2} };
int dist[50][50][4];
const int INF = 987654321;


int bfs() {
	queue<pp> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 4; k++)
				dist[i][j][k] = INF;

	for (int i = 0; i < 4; i++) {
		q.push({ i, {0, door[0].first, door[0].second} });
		dist[door[0].first][door[0].second][i] = 0;
	}

	while (!q.empty()) {
		int d = q.front().first;
		int c = q.front().second[0], x = q.front().second[1], y = q.front().second[2];
		q.pop();
		// 2-1. ��ǥ��  . # �϶��� �� ������ �״�� ���� 
		if (home[x][y] == '.' || home[x][y] == '#') {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || home[nx][ny] == '*')
				continue;
			q.push({ d, {c,nx,ny} });
			dist[nx][ny][d] = c;
		
		}
		else {		// 2-2. ! �϶��� ���� ���⿡�� �ٶ���� �� �� 3������ ����. ��,��, ���� => �̶��� ������ �Ÿ��� ���Ͽ� ���� ��츸 ť�� Ǫ��.
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || home[nx][ny] == '*')
					continue;
				int cost = d == i ? 0 : 1;

				if (dist[nx][ny][i] >= c + cost) {
					dist[nx][ny][i] = c + cost;
					q.push({ i, {c + cost,nx,ny} });
				}
			}
		}
		
	}
	int answer = INF;
	for (int i = 0; i < 4; i++) {		// 3. �� �� ���� �Ÿ� �� �ſ��� �ּ� ���� Ȯ��
		answer = answer < dist[door[1].first][door[1].second][i] ? answer : dist[door[1].first][door[1].second][i];
	}
	
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			home[i][j] = str[j];
			if (str[j] == '#') {
				door.push_back({ i,j });	// 1. �� ���� ��ǥ�� ����
			}
		}
	}
	cout << bfs();

	return 0;
}