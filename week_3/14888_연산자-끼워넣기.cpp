#include <iostream>
#include <vector>
#include <algorithm>

// ���� 14888�� ������ �����ֱ�

using namespace std;

// �ִ� 10!������ ���Ʈ���� => ��� �̿�.
// n�� �� �������� �迭�� �־��ְ� sort. �ִ밪 �ּҰ� ���.

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