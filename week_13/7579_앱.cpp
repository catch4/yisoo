// 백준 7579번 앱

/*
접근 : 전형적인 dp 문제
M 메모리 확보에 필요한 최소의 비용 => 비용 당 메모리가 최대가 되어야 한다.

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
	// m 이상 확보되었으면 최소이므로 끝.
	for (int i = 0; i <= sum; i++) {
		if (dp[i] >= m) {
			cout << i;
			break;
		}
	}
	return 0;
}