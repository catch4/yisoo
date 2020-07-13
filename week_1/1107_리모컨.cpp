#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

// ���� 1107 ������

using namespace std;

// 1. ���� �ִ� ���� ������ ���� ������ ��� �� Ȯ��.
// 2. 0���� �鸸���� ���鼭 ������ �ּ�Ƚ�� Ȯ��
// �ð����⵵: O(nlogn)

bool num[10];
vector<int> v;

// 1.
void count(int n) {
	int x = n;

	if (x == 0) {
		if (num[x]) return;
		v.push_back(n);
	}
	// ���� ���ڷ� ���� ��.
	while (x > 0) {
		if (num[x % 10]) return;
		x /= 10;
	}
	v.push_back(n);
}

int main() {
	memset(num, 0, sizeof(num));
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int idx;
		cin >> idx;
		num[idx] = true;
	}
	for (int i = 0; i < 1000000; i++) {
		count(i);
	}
	// ���� 100���� ���¿��� ����.
	int answer = abs(n - 100);

	// ������ ���� Ȯ��.
	for (int val : v) {
		int cnt = to_string(val).length() + abs(val - n);
		answer = answer > cnt ? cnt : answer;
	}

	cout << answer;

	return 0;
}
