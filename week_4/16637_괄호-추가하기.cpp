#include <iostream>
#include <string>
#include <vector>
#include <deque>
// 백준 16637번 괄호 추가하기.

using namespace std;

// 1. 브루트포스이므로 괄호가 가능한 모든 조합 먼저 생성
// 2. 조합을 확인하면서 계산.
// 2-1. 괄호를 먼저 계산해서 deque에 포함. 
// 2-2. deque를 돌면서 값 계산

int n, op;
vector<string> arr;

// 
string calc(char a, char b, char c) {
	int A = a - '0';
	int C = c - '0';
	if (b == '+')
		return to_string(A + C);
	if (b == '-')
		return to_string(A - C);
	if (b == '*')
		return to_string(A * C);
}

// 2-1.
string cal(deque<string> s) {
	long long a = stoll(s[0]);
	long long b = stoll(s[2]);
	if (s[1] == "+")
		return to_string(a + b);
	if (s[1] == "-")
		return to_string(a - b);
	if (s[1] == "*")
		return to_string(a * b);
}

//2-2.
string calString(deque<string> s) {
	while (s.size() > 1) {
		deque<string> st;
		for (int i = 0; i < 3; i++) {
			st.push_back(s.front());
			s.pop_front();
		}
		s.push_front(cal(st));
	}
	return s[0];
}

// 1.
void count(int end, string val) {
	if (end == val.length()) {
		arr.push_back(val);
		return;
	}
	int t = val.length() == 0 ? -2 : val[val.length() - 1] - '0';

	for (int i = t + 2; i < n / 2; i++) {
		count(end, val + to_string(i));
	}
	return;
}

int main() {
	cin >> n;
	string str;
	cin >> str;
	deque<string> st;
	int answer = -2147483648;

	//1.
	for (int i = 1; i <= n / 2; i++) {
		count(i, "");
	}
	for (string a : arr) {
		deque<string> temp;
		int start = 0;

		// 2. 돌면서 확인
		for (int i = 0; i < a.length(); i++) {
			// 괄호 표시 전까지 deque에 넣기.
			int end = 2 * (a[i] - '0') + 1;
			for (int j = start; j < end - 1; j++) {
				string ss;
				ss += str[j];
				temp.push_back(ss);
			}
			temp.push_back(calc(str[end - 1], str[end], str[end + 1])); // 괄호 계산
			start = end + 2;
		}
		// 괄호 계산된 식 계산
		for (int i = start; i < n; i++) {
			string ss;
			ss += str[i];
			temp.push_back(ss);
		}
		answer = answer > stoi(calString(temp)) ? answer : stoi(calString(temp));
	}

	if (arr.size() == 0)
		answer = str[0] - '0';
	cout << answer << endl;

	return 0;
}