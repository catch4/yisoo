// 백준 10159번 저울

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int n, m;

int arr[101][101];
bool v[101];

int dfs(int s) {
	stack<int> st;
	memset(v, 0, sizeof(v));
	st.push(s);
	
	int ret = 0;
	while (!st.empty()) {
		int from = st.top();
		st.pop();
		v[from] = 1;
		for (int i = 1; i <= n; i++) {
			if (arr[from][i] ==-1 && !v[i]) {
				st.push(i);
			}
		}
	}
	
	st.push(s);
	while (!st.empty()) {
		int from = st.top();
		st.pop();
		v[from] = 1;
		for (int i = 1; i <= n; i++) {
			if (arr[from][i] ==1 && !v[i]) {
				st.push(i);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (v[i]) ret++;
	}

	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = -1;
	}

	for (int i = 1; i <= n; i++) {
		cout << n - dfs(i) << "\n";
	}


	return 0;
}