// ���� 1029�� �׸� ��ȯ
/*
��Ʈ����ũ�� �̿��� Ǯ��.

��Ʈ����ũ�� �����س�����, �ͼ����� �ʾ� ����� �ڵ带 �ۼ����� ����.
*/



#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int p[15][15];
int dp[1 << 15][15][10];

int solve(int here, int visit, int price) {
	int& ret = dp[visit][here][price];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < n; i++) {
		if ((1 << i) & visit) continue;
		if (p[here][i] >= price)
			ret = max(ret, 1 + solve(i, visit | (1 << i), p[here][i]));
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			p[i][j] = tmp[j] - '0';
		}
	}
	memset(dp, -1, sizeof(dp));

	cout << solve(0, 1, 0);
	return 0;
}