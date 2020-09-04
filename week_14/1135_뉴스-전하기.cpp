// ���� 1135�� ���� ���ϱ�

/*
dp�� dfs�� �߰� �� ���..?

Ǯ�� :
1. ����Ʈ���� �ҿ�Ǵ� �ð� �� ū �ð����� ��ȭ������
2. ����Ʈ�� �ҿ� �ð� ���
	2-1. ����Ʈ���� ������ 0 return.
	2-2. ����Ʈ���� ������ �����ؼ� �� �� �ּҷ� �ҿ�Ǵ� �ð� ã��.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
int n;
vector<int> p[51];
int dp[51];	// n���� ���� ��+���� ���Ͽ��� ������ �� ���Ǵ� �ð� (����Ʈ�� ��� ������ �� ���Ǵ� �ð� �� �ּ�)

bool cmp(int a, int b) {
	return dp[a] > dp[b];
}

int solve(int num) {
	int& ret = dp[num];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < p[num].size(); i++) {
		int to = p[num][i];
		solve(to);
	}
	
	sort(p[num].begin(), p[num].end(), cmp);
	ret =0 ;
	for (int i = 0; i < p[num].size(); i++) {
		int to = p[num][i];
		ret = max(ret, i + 1 + dp[to]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		if (u == -1) continue;
		p[u].push_back(i);
	}
	cout<<solve(0);

	return 0;
}