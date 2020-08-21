// 백준 9935번 문자열 폭발

/*
폭발 문자열하고 같으면 대조 확인
폭발 문자열이면 폭발시킴
아니면 원상복귀 후 다시 문자열 더하기
*/

#include <iostream>
#include <string>

using namespace std;

typedef pair<char, int> pi;
string str, bomb;
int len;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str >> bomb;
	len = bomb.length();
	string ans;
	for (int i = 0; i < str.length(); i++) {
		ans += str[i];
		if (ans.back()==bomb[len-1]) {
			string tmp;
			for (int j = len - 1; j >= 0; j--) {
				if (ans.back() == bomb[j]) {
					tmp = ans.back() + tmp;
					ans.pop_back();
				}
				else {
					ans += tmp;
					break;
				}
			}
		}
	}

	if (ans.length())
		cout << ans;
	else
		cout << "FRULA";
	return 0;
}