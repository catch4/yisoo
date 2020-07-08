#include <iostream>
#include <algorithm>
#include <vector>

// ���� 2352�� �ݵ�ü ����

using namespace std;

// 0. LIS�˰��� => DP => �ð� �ʰ�
// 1. �̺�Ž��

int val[40000];

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	arr.push_back(val[0]);

	for (int i = 1; i < n; i++) {
		int idx = arr.size() - 1;
		// ���� �迭�� ������ ���Һ��� ���� ũ�ٸ�
		if (val[i] > arr[idx])
			arr.push_back(val[i]);
		// �׷��� �ʴٸ� �ڸ� ã��.
		else {
			int left = 0, right = idx;
			while (left < right) {
				int mid = (left + right) / 2;
				if (val[i] > arr[mid]) 
					left = mid + 1;
				else 
					right = mid;
			}
			arr[right] = val[i];
		}
	}

	cout << arr.size() << endl;

	
	
	return 0;
}