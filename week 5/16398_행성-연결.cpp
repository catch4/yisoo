// ���� 16398�� �༺ ����

// 1. �׷����� ��� �����ϴ� �ּ� ��� =>ũ�罺Į �˰���.
// 2. ���� + ����Ŭ�� �������� �ʴ� ��츸 ����
// 2-1. ����Ŭ ���� => union-find.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> node;
int n;
int map[1000][1000];
int v[1000];

bool cmp(node a, node b) {
	return a.second < b.second;
}

// 2-1.
int find(int num) {
	if (num == v[num]) return num;
	return v[num] = find(v[num]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<node> arr;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++) {
		v[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			arr.push_back({ {i,j},map[i][j] });
		}
	}
	sort(arr.begin(), arr.end(), cmp);

	int ret = n - 1;
	long long ans = 0;
	for (node p : arr) {
		int x = p.first.first, y = p.first.second, c = p.second;
		int a = find(x);
		int b = find(y);
		if (a != b) {
			v[b] = a;	// 2-1.union , ������ ���ڰ� ���� ������ ��ġ��.
			ret--;
			ans += c;
		}
		if (ret == 0)
			break;
	}
	cout << ans;
	return 0;
}