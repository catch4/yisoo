#include <iostream>
#include <stack>
#include <utility>

 // ���� 2504�� ��ȣ�� ��

using namespace std;

// 1. ��ȣ�� ���� ��뿡 ��� 
// 2. ��ȣ �ȿ� ��ȣ�� ���� ��� �ʿ�.
// 2-1. �⺻���� ��� = ()�̸� 2�� []�̸� 3�� ���. ��ȣ�� �ϼ��� ��� 2,3�� ���
// 2-2. ��ȣ �� ��ȣ�� ��� ���ÿ� �ϳ� �̻� �׿����ִ�. => ��ȣ �ϼ��� �� ������ empty�� �ƴ϶�� �ϼ��� ���� ���ϱ�(�׿����ִ� ��ȣ�� ������ 1���̶�� �ϼ��� ������ �Ҵ�)
// 3. pair�� �̿��� ���� �ױ�.
// 4. ���� ��� ���� �� ������ ������� �ʴٸ� ��ȣ �ҿ���.

int main() {
	string p;
	cin >> p;

	// 1 + 3.
	stack<pair<char, int>> st;
	int answer = 0;
	for (int i = 0; i < p.length(); i++) {
		// 1.
		if (p[i] == '(' || p[i] == '[') {
			st.push({ p[i],1 });
		}
		else {
			// 1.
			if (st.empty()) {
				answer = 0;
				break;
			}
			char open = st.top().first;
			if (p[i] == ')' && open == '[') {
				answer = 0;
				break;
			}
			else if (p[i] == ']' && open == '(') {
				answer = 0;
				break;
			}
			// 2.
			else {
				int val = st.top().second;
				st.pop();
				// 2-1.
				if (p[i] == ')' && open == '(') {
					val *= 2;
				}
				else {
					val *= 3;
				}
				// 2-2. ��ȣ �� ��ȣ
				if (!st.empty()) {
					pair<char, int> pi = st.top();
					if (pi.second == 1)
						pi.second = val;
					else
						pi.second += val;
					st.pop();
					st.push(pi);
				}
				// 2-2. ��ȣ �� ��ȣ�� �ƴ϶�� 
				else
					answer += val;
			}

		}
	}

	// 4.
	if (!st.empty())
		answer = 0;
	cout << answer << endl;
	
	return 0;
}