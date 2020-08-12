// ���� 3015�� ���ƽý� �����

/*
���� �̿� => �з� ��Ʈ Ȯ��
+ ������׷�(6549��)�ϰ� ����� ����.

�⺻���� ������ A,B ���̿� A/B �Ѻ��� ū ���� ����� �Ѵ�.
=> ���ÿ��� ������ ���� ���� ����� �Ѵ�.

*/

#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, long long> pi;
int n,p[500001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	long long ans = 0;
	stack<pi> st;
	
	// �� �� Ȯ��
	for (int i = 0; i < n; i++) {	
		// i��°���� ���� ���� ����.
		while (!st.empty() && st.top().first <p[i]) {
			ans++;	// 
			st.pop();
		}
		long long cnt = 0;
		// �ִ� ���� ��찡 �� �� ���ӵǾ� �ִ� �� Ȯ��, ���ӵ� �� ���ٸ� top�� �ִ� ������� �� �̷�� ����.
		if(st.size())
			cnt = st.top().first == p[i] ? st.top().second+1 : 1;
		ans += cnt;
		
		st.push({ p[i],cnt });
	}
	cout << ans;
	return 0;
}