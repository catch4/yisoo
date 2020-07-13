// ���� 1806�� �κ���

// �������� ������ ����.
// start, end,sum�� �ΰ� ������ ���� s�̻��̸� �ּҰ� Ȯ��
// start�� ���� ����, end�� ���� ��
// ���� sum�� s���� ������ end�� +1�ؼ� ������ �ø���.
// ���� s�̻��̸� �ּҰ� Ȯ���ϰ� start�� �ϳ� ���δ�.
// 

#include <iostream>

using namespace std;

int n, s;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int sum = arr[0];
	int cnt = 1;
	int start = 0, end = 0;
	int answer = n + 1;

	while (end < n) {
		if (sum >= s) {
			answer = answer > cnt ? cnt : answer;
			sum -= arr[start];
			start += 1;
			cnt--;
		}
		else if (sum < s) {
			end++;
			sum += arr[end];
			cnt++;
		}		
	}
	if (answer == n + 1)
		answer = 0;
	cout << answer;

	return 0;
}