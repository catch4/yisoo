#include <iostream>
#include <vector>
#include <algorithm>

// ���� 7453�� ���� 0�� �� ����

using namespace std;

// n�� ũ�� �ʴٸ� ���Ʈ ���� but, n�� 4000�̹Ƿ� N^2* logN^2 ������ ������ �Ѵ�. => �̺� Ž�� Ȱ��
// �ϴ� �� �׷�(a,b / c,d)���� ���� �� ������ ���� �迭�� ����. => ������ 1+1+1+1 �̳�, 2+2�̳� 4�� ���� ���Ѱ���.
// a,b�� ���� �������� c,d�� �հ��� �� ���� 0�� ��츦 �̺�Ž������ ã�´�.
// ã�� �� �߿��� �� answer�� ���� int������ �Ѿ ���� �ִٴ� �Ͱ� �� �׷� �� ���� ���� ���� ���� �� �ִ�. => upper_bound-lower_bound�� ���� �ߺ����� ó��.

int n;

int main() {
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	vector<int> ab(n * n), cd(n * n);
	// �� ���ϱ�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab[i * n + j] = a[i] + b[j];
			cd[i * n + j] = c[i] + d[j];
		}
	}
	// cd�� �����ؾ� �̺�Ž�� ����.
	sort(cd.begin(), cd.end());

	long long answer = 0;
	for (int i = 0; i < n * n; i++) {
		int left = 0, right = n * n;

		// �̺�Ž��
		while (left < right) {
			int mid = (left + right) / 2;
			// �ߺ��� ó��.
			if (ab[i] + cd[mid] == 0) {
				answer += upper_bound(cd.begin(), cd.end(), -ab[i]) - lower_bound(cd.begin(), cd.end(), -ab[i]);
				break;
			}
			else if (ab[i] + cd[mid] > 0) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
	}
	cout << answer << endl;
	return 0;
}