// ���� 7579�� ��

/*
���� : �������� dp ����
M �޸� Ȯ���� �ʿ��� �ּ��� ��� => ��� �� �޸𸮰� �ִ밡 �Ǿ�� �Ѵ�.

dp[cost ] = maxMemory;
dp[cost] = max(dp[cost], dp[cost-c[i]] + memory[i]);

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int mem[101], c[101];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> mem[i];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		sum += c[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= c[i]; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + mem[i]);
		}
	}
	// m �̻� Ȯ���Ǿ����� �ּ��̹Ƿ� ��.
	for (int i = 0; i <= sum; i++) {
		if (dp[i] >= m) {
			cout << i;
			break;
		}
	}
	return 0;
}