// ���� 10830�� ��� ����

/*
�������� ���� ���� ����

b�� 1000���̶� �޸������̼��� �ؾ��ϳ� �;����� 
�ܼ��� ��� ȣ��ε� �ذ�. 
�ð��ʰ��� �Ȱ��� �Լ��� �� �� ȣ���ϴ� ���� �����Ͽ� �ذ�.

*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vec;
int n;
ll b;
vec arr;

// ��� ���
vec cal(vec a, vec b) {
	vec ret(n, vector<ll>(n, 0));
	vector<ll> tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll& t = ret[i][j];
			for (int k = 0; k < n; k++) {
				t += a[i][k] * b[k][j];
			}
			t = t % 1000;
		}
	}
	return ret;
}

// ��� ȣ��
vec solve(vec a, ll num) {
	if (num == 1) return a;
	if (num % 2 == 0) {
		vec half = solve(a, num / 2); // �ð��ʰ� ����
		return cal(half, half);
	}
	else {
		return cal(solve(a, num - 1), a);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> b;

	vector<ll> tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll t;
			cin >> t;
			tmp.push_back(t);
		}
		arr.push_back(tmp);
		tmp.clear();
	}
	vec ret = solve(arr, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ret[i][j]%1000 << " ";
		}
		cout << "\n";
	}

	return 0;
}