#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// ���� 1516�� ���� ����

using namespace std;

// ���� ����
// ����� ������ 0�� ������ �ϳ��� ����.
// �����ϸ鼭 ���� ����� �� �ð��� ���� �ð��� ������ �ð� �� ���� ū ������ �Ҵ�.
// �ٽ� ����� ������ 0�� ���� ť�� push

typedef pair<int, int> pi;
int n;
int connect[501];
int total[501];
int cost[501];
vector<int> need[501];

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		connect[i] = 0;
		total[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		while (true) {
			int input;
			cin >> input;
			if (input == -1)
				break;
			need[input].push_back(i);
			connect[i]++;
		}
	}


	// ť�� (���, �ǹ� ��ȣ) ����.
	queue<pi> q;

	// ������ 0�� �ǹ� push
	for (int i = 1; i <= n; i++) {
		if (connect[i] == 0) {
			q.push({ cost[i],i });
		}
	}
	
	while (!q.empty()) {
		int c = q.front().first;
		int from = q.front().second;
		q.pop();

		// ����� �ǹ��� �� �ð� ����.
		for (int i = 0; i < need[from].size(); i++) {
			int to = need[from][i];
			connect[to]--;
			total[to] = max(total[to], total[from] + c);
			if (connect[to] == 0)
				q.push({ cost[to],to });
		}
	}


	for (int i = 1; i <= n; i++) {
		cout << total[i]+cost[i] << endl;
	}
	return 0;
}