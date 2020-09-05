// ���� 5015�� ls

/*
���� :
	�����Ͽ��� ������ �����ߴ� ����. �̹��� �ٽ� Ǯ���ϸ鼭 ��������.

Ǯ�� :
	dp 
	dp[���Ͻ�����ġ][���Ͻ�����ġ]�� �����Ͽ� ���� ���ڿ��� ��ġ�ϸ� 1, �ƴϸ� 0
	
*/

#include <iostream>
#include <cstring>

using namespace std;

string pattern,file;
int n;
int dp[101][101];


bool check(int p, int f) {
		
	int& ret = dp[p][f];
	if (ret != -1)
		return ret;

	if (p < pattern.size() && f < file.size() && pattern[p] == file[f])
		return check(p + 1, f + 1);	
	if (p == pattern.size() && f == file.size())
		return ret = 1;
	if (pattern[p] == '*') {
		if (check(p + 1, f) || (f<file.size() && check(p,f+1))) {
			
			return ret = 1;
		}
	}
	
	return ret = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> pattern;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(dp, -1, sizeof(dp));
		cin >> file;
		if (check(0,0))
			cout << file << "\n";
	}

	return 0;
}