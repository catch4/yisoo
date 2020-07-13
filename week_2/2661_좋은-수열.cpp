#include <iostream>
#include <string>

 // ���� 2661�� ���� ����

using namespace std;

// ���� �����
// ���� ������ Ȯ��

int n;

// ���� �������� Ȯ��
bool isGood(string val) {
	// 1ĭ���� n/2ĭ����.
	for (int i = 1; i <= val.length() / 2; i++) {
		for (int j = 0; j < val.length()-i; j++) {
			bool flag = true;
			for (int k = j; k < j + i; k++) {
				if (k + i > val.length())
					break;
				if (val[k] != val[k + i]) // ���� �ʴٸ� ���� ����
					flag = false;
			}
			if (flag) // ���� ����
				return false;
		}
	}
	return true;
}

void count(string val) {
	if (val.length() == n) {
		// ó�� �����ϴ� ���� ���� ���� ��.
		cout << val;
		exit(0);
	}
	for (int i = 1; i <= 3; i++)
		if (isGood(val + to_string(i)))
			count(val + to_string(i));
	
	return;
}


int main() {
	cin >> n;
	count("");
	return 0;
}