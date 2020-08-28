// ���� 7575�� ���̷���
/*
���� : 
���ڿ� �˻� =>KMP�̿�

Ǯ�� :
1 .���α׷� ���̰� ���� ª�� ���� �������� ���ڿ� ����
+
2. ��� ���α׷��� ���� �� �� �����⸦ ��� �˻�

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int p[101][1001];
int len[101];

// tmp[ : i] �� ���λ�, ���̻簡 ������ ���� �� ���ڿ� = pi[i]
vector<int> getPi(vector<int> tmp) {
	int size = tmp.size();
	vector<int> pi(size, 0);

	int begin = 1, matched = 0;
	while (begin + matched < size) {
		if (tmp[begin + matched] == tmp[matched]) {
			matched++;
			pi[begin+ matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

// ��� ���α׷��� ���� tmp �˻�
bool kmp(vector<int> tmp, vector<int> pi) {
	int size = tmp.size();

	// ���α׷� 1���� n���� �յ� �˻�
	for (int i = 0; i < n; i++) {
		// ������ �迭 �˻�
		int begin = 0, matched = 0;
		bool flag = false;
		while (begin <= len[i] - size) {
			if (matched < size && (p[i][begin + matched] == tmp[matched])) {
				matched++;
				if (matched == size) {
					// ã�� ���
					flag = true;
					break;
				}
			}
			else {
				if (matched == 0)
					begin++;
				else {
					begin += matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		// ã���� ��� ���� ���α׷� �˻�
		if (flag) continue;

		// ����� �˻�
		reverse(tmp.begin(), tmp.end());
		begin = 0, matched = 0;
		while (begin <= len[i] - size) {
			if (matched < size && (p[i][begin + matched] == tmp[matched])) {
				matched++;
				if (matched == size) {
					flag = true;
					break;
				}
			}
			else {
				if (matched == 0)
					begin++;
				else {
					begin += matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		// ������� �� ã�� ���� ���̷��� ����.
		if (!flag) return false;
	}
	// ��� ���̷��� �ִ�.
	return true;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	int minLen = 1000;
	int minIdx = 0;
	for (int i = 0; i < n; i++) {
		cin >> len[i];
		if (minLen > len[i]) {
			minIdx = i;
			minLen = len[i];
		}
		for (int j = 0; j < len[i]; j++) 
			cin >> p[i][j];
	}

	for (int j = 0; j <= len[minIdx] - k; j++) {
		// 1. ���� ª�� ���α׷� �������� �迭 ����
		vector<int> tmp;
		for (int a = j; a < j + k; a++) {
			tmp.push_back(p[minIdx][a]);
		}
		vector<int> pi = getPi(tmp);
		// ��� ���α׷��� �ִٸ� ����
		if (kmp(tmp,pi)) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";


	return 0;
}