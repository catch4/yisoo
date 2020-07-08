#include <iostream>
#include <string>
#include <map>

// ���� 4195�� ģ�� ��Ʈ��ũ

using namespace std;

// union find�� ���� 
// ��ǥ���� union find �����̹Ƿ� union / find �Լ� ����.
// �ٸ� ������ �����ؾ� �ϹǷ� ������ ������ �ٸ� �迭 ����.
// �ٸ� ����¿��� �ð��� ���� �ɷ� ���� ã�ƺ����� �㹫�� "\n";;

int num[200001];
int p[200001];

int findP(int i) {
	if (i == p[i]) return i;
	return p[i] = findP(p[i]);
}

int Union(int a, int b) {
	int x = findP(a);
	int y = findP(b);
	if (x != y) {
		p[y] = x;
		num[x] += num[y];
	}
	return num[x];
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		map<string, int> m;
		int n;
		cin >> n;
		int idx = 0;
		for (int i = 1; i < 2*n+1; i++) {
			p[i] = i;
			num[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			
			if (m.find(a) == m.end())  {
				m[a] = ++idx;
			}
			 if (m.find(b) == m.end()) {
				m[b] = ++idx;
			}

			 cout << Union(m[a], m[b]) << "\n";
		}
	}


	return 0;
}