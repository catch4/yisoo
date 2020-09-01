// ���� 17780�� ���ο� ���� 

/*
�׳� ���� ����
*/

#include <iostream>
#include <vector>

using namespace std;

struct Horse {
	int num, x, y, dir;
};

typedef pair<int, int> pi;
int n, k;
int board[13][13];
pi pos[11];	// n��° ���� ��ġ
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

vector<Horse> h[13][13];	// (i,j)�� �ִ� ��

// ���� �ٲٱ�
int change(int dir) {
	if (dir == 0) return 1;
	if (dir == 1) return 0;
	if (dir == 2) return 3;
	if (dir == 3) return 2;
}

// �� �̵��� �� �����Ǹ� false, �����Ǹ� true ��ȯ
bool go(int x, int y, int idx, int dir) {
	int nx = x + dx[dir], ny = y + dy[dir];
	// �����ų�, �Ķ����϶�
	if (nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == 2) {
		int ndir = change(dir);
		int nnx = x + dx[ndir], nny = y + dy[ndir];
		h[x][y][0].dir = ndir;
		// �ݴ� ���⵵ �Ķ����϶�
		if (board[nnx][nny] == 2) {
			return true;
		}
		else {
			// �Ķ����� �ƴҶ� ���
			if (!go(x, y, idx, ndir))
				return false;
			return true;
		}
	}
	// �� ���϶�
	else if (board[nx][ny] == 0) {
		// ������ �־��ֱ�
		for (int i = 0; i < h[x][y].size(); i++) {
			h[nx][ny].push_back(h[x][y][i]);
			int now = h[x][y][i].num;
			pos[now] = { nx,ny };		// �� ��ġ ����ȭ
		}
		h[x][y].clear();
		return h[nx][ny].size() < 4;
	}
	// ���� ���� ��
	else {		
		// ������ �־��ֱ�
		for (int i = h[x][y].size()-1; i >=0; i--) {
			h[nx][ny].push_back(h[x][y][i]);
			int now = h[x][y][i].num;
			pos[now] = { nx,ny };
		}
		h[x][y].clear();
		return h[nx][ny].size() < 4;

	}

}

int turn(int cnt) {
	// 1�� ������ �̵�
	for (int i = 1; i <= k; i++) {
		int x = pos[i].first, y = pos[i].second;
		// i��° ���� �ش� ��ġ���� ���� �Ʒ��� �ִ� ���� �ƴ϶�� pass
		if (h[x][y][0].num != i)
			continue;
		int dir = h[x][y][0].dir;
		// �Ͽ����� �� ���� return
		if (!go(x, y, i, dir))
			return cnt;
	}
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];


	for (int i = 1; i <= k; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		h[x][y].push_back({ i,x,y,dir-1 });
		pos[i] = { x,y };
	}
	int answer = 0;
	bool flag = false;
	for (int i = 1; i <= 1000; i++) {
		answer = turn(i);
		if (answer) {
			flag = true;
			break;
		}
	}
	
	if (flag)
		cout << answer;
	else
		cout << -1;

	return 0;
}