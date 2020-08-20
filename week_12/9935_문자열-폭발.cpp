// ���� 9935�� ���ڿ� ����

/*
�з��� ���� �����ִ� �� ���� ���� ���

*/

#include <iostream>
#include <string>
#include <stack>

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