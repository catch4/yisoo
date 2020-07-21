// ���� 3980�� ���� ���

/*
11���� ��ġ�ϴ� ���� �ִ� 11! => �� 4õ�� = 1�� �ȿ� ����
+
��� ������ ��� �����ǿ� ���� �ɷ�ġ�� �ִ� ���� �ƴϹǷ� ����� �� ª��

*/

#include <iostream>
#define SIZE 11
using namespace std;

int player[SIZE][SIZE];
int answer;
bool v[SIZE];

void dfs(int cnt, int val) {
	if (cnt == 11) {
		answer = answer > val ? answer : val;
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		if (!v[i] && player[cnt][i] !=0) {
			v[i] = true;
			dfs(cnt + 1, val + player[cnt][i]);
			v[i] = false;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		answer = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cin >> player[i][j];
			}
		}
		dfs(0, 0);
		cout << answer << "\n";
	}
	

	return 0;
}