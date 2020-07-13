#include <iostream>
#include <vector>
#include <algorithm>

// 백준 14888번 연산자 끼워넣기

using namespace std;

// 최대 10!가지라서 브루트포스 => 재귀 이용.
// n번 다 돌았으면 배열에 넣어주고 sort. 최대값 최소값 출력.

int n;
int arr[11];
vector<int> ans;

int notice(int idx, int val, int operand) {
	switch (idx) {
	case 0: return val + operand;
	case 1: return val - operand;
	case 2: return val * operand;
	case 3: return val / operand;
	}
}

void count(int cnt, int val, vector<int> op) {
	if (cnt == n) {
		ans.push_back(val);
		return;
	}
	int operand = arr[cnt];
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			int new_val = notice(i, val, operand);
			op[i]--;
			count(cnt + 1, new_val, op);
			op[i]++;
		}
	}
	
	return;
}

int main() {
	cin >> n;
	vector<int> op(4, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];
	count(1, arr[0], op);
	sort(ans.begin(), ans.end());

	cout << ans[ans.size() - 1] << endl;
	cout << ans[0] << endl;

	return 0;
}