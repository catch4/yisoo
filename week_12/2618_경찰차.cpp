// 백준 2618번 경찰차

/*
실패

풀이
dp

*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pi;
int n, w;
int car[1001];
pi e[2][1001];
int dp[1001][1001];

int dist(pi a, pi b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int one, int two) {
	if (one == w || two == w)
		return 0;

	int& ret = dp[one][two];
	if (ret != -1) return ret;

	ret = 987654321;
	int next = max(one, two) + 1;
	int a = solve(next, two) + dist(e[0][one], e[0][next]);
	int b = solve(one, next) + dist(e[1][two], e[1][next]);

	return ret = min(a, b);
}

void print(int one, int two) {
	if (one == w || two == w)
		return;

	int next = max(one, two) + 1;
	int a = solve(next, two) + dist(e[0][one], e[0][next]);
	int b = solve(one, next) + dist(e[1][two], e[1][next]);

	if (a > b) {
		cout << "2" << endl;
		print(one, next);
	}
	else {
		cout << "1" << endl;
		print(next, two);
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> w;
	memset(dp, -1, sizeof(dp));
	e[0][0] = { 1,1 };
	e[1][0] = { n,n };

	for (int i = 1; i <= w; i++) {
		int x, y;
		cin >> x >> y;
		e[0][i] = e[1][i] = { x,y };
	}
	
	cout << solve(0, 0) << endl;
	print(0, 0);


	return 0;
}