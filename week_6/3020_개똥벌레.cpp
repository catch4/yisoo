// ���� 3020�� ���˹���

// �̺� Ž���� �̿��� ����
// 1. �������� ������ ����
// 2. ������ ������ �ɸ��� ���� Ȯ��
// lower_bound�� �̹� �̺�Ž���ε� ó���� ��û�ϰ� �̺�Ž���س��� �ٽ� lowerbound�� ���;

#include <iostream>
#include <algorithm>

using namespace std;

int n, h;
int jong[100001];
int suk[100001];


int check(int val) {
	int ret = n;
	ret -=(lower_bound(jong, jong + n / 2, h - val + 1) - jong);
	ret -= lower_bound(suk, suk + n / 2, val) - suk;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> h;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (i % 2 == 0) suk[i / 2] = temp;
		else jong[i / 2] = temp;
	}

	sort(jong, jong + n / 2);
	sort(suk, suk + n / 2);

	int answer = n + 1;
	int cnt = 1;
	for (int i = 1; i <= h; i++) {
		int ret = check(i);
		if (ret == answer) {
			answer = ret;
			cnt++;
		}
		else if (ret < answer) {
			answer = ret;
			cnt = 1;
		}
		
	}
	cout << answer << " " << cnt;
	
	return 0;
}