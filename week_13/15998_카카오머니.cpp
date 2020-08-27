// 백준 15998번 카카오머니 

/*
접근 :
최대 공약수 문제임을 인지 못함
-> 풀이 실패

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
long long a[300001], b[300001];

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	ll bal = 0;
	ll minM = 0;
	ll now = 0;
	vector<ll> m;
	for (int i = 0; i < n; i++) {
		if (a[i] + bal < 0) {
			now = b[i] - a[i] - bal;
			m.push_back(now);
			minM = max(b[i], minM);
		}
		else {
			if (b[i] != a[i] + bal) {
				cout << -1;
				return 0;
			}
		}
		bal = b[i];
	}
	if (m.size() == 0) {
		cout << 1;
	}
	else {
		ll now = m[0];
		for (int i = 1; i < m.size(); i++) {
			now = gcd(now, m[i]);
		}

		if (now <= minM)
			cout << -1;
		else
			cout << now;
	}
	
	
	return 0;
}