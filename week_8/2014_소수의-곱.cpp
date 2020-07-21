// ���� 2014�� �Ҽ��� ��

/*
���� : 
1) n��° ���ڰ� ���� ������ ������Ű�� ������ ������Ű�� �� �Ǵ� => �ð��ʰ�
2) �켱���� ť�� �̿��Ͽ� n��°���� pop.

Ǯ��:
1. �켱���� ť�� �Է¹��� �Ҽ��� push
2. pop�ϰ� �ش� ���� �Է¹��� �Ҽ��� ���Ͽ� ������ ���� �ʴ´ٸ� push
3. �ߺ� ���Ÿ� ���� pop�� ���� �Ҽ��� �������ٸ� break.
*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int prime[100];
int n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k >> n;
	
	for (int i = 0; i < k; i++) {
		cin >> prime[i];
	}
	priority_queue<int, vector<int>, greater<int>>pq;

	// 1.
	for (int i = 0; i < k; i++) {
		pq.push(prime[i]);
	}
	int val = 0;

	while (n--) {
		val = pq.top();
		pq.pop();
		
		for (int i = 0; i < k; i++) {
			long long x = (long long)val * prime[i];
			if (x >= INT_MAX) continue;	
			pq.push(val * prime[i]);	// 2.
			if (val % prime[i] == 0) break;	// 3
		}
	}

	cout << val;

	return 0;
}