#include <iostream>
#include <string>
#include <vector>
#include <deque>
// ���� 16637�� ��ȣ �߰��ϱ�.

using namespace std;

// 1. ���Ʈ�����̹Ƿ� ��ȣ�� ������ ��� ���� ���� ����
// 2. ������ Ȯ���ϸ鼭 ���.
// 2-1. ��ȣ�� ���� ����ؼ� deque�� ����. 
// 2-2. deque�� ���鼭 �� ���

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

		// 2. ���鼭 Ȯ��
		for (int i = 0; i < a.length(); i++) {
			// ��ȣ ǥ�� ������ deque�� �ֱ�.
			int end = 2 * (a[i] - '0') + 1;
			for (int j = start; j < end - 1; j++) {
				string ss;
				ss += str[j];
				temp.push_back(ss);
			}
			temp.push_back(calc(str[end - 1], str[end], str[end + 1])); // ��ȣ ���
			start = end + 2;
		}
		// ��ȣ ���� �� ���
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