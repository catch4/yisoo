// 백준 1701번 Cubeeditor

/*
풀이 실패
kmp 참고


*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;

int getPi(string N) {
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return *max_element(pi.begin(),pi.end());
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str;

	int size = str.length();
	int ans = 0;
	for (int i = 0; i < size;i++) {
		string N;
		for (int j = i; j < size; j++) {
			N += str[j];
		}
		ans = max(ans, getPi(N));
	}
	cout << ans;
	
	return 0;
}