// ���� 17825�� �ֻ��� ������

/*
���� : 
Turn���� ������ ���� 4^10�̹Ƿ� ���Ʈ���� ���� + ��Ʈ��ŷ���� ��� ���̱�.

Ǯ�� :
1. ����?���� �� �� �ִ� ���� ������ => �迭�� ���Ǹ��� ���� ������ ��ġ�� ǥ��
2. dice[now]�� ������ �� ��ġ�� �ٸ� ���� �ִٸ� pass
3. �ٸ� �� ���ٸ� �ش� ���� ���ϰ� ���ȣ��
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dice[10];		// �ֻ���
int horse[4];		// ���� ��ġ
// ĭ�� ������ ���� ��ġ.
int kan[33] = { 	1,2,3,4,5,	21,7,8,9,10,	24, 12,13,14,15,	29,17,18,19,20,	32, 22, 23, 26, 25,	26, 30, 26, 27, 28,	31,	20, -1 };
int score[33] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,22,24,25,26,27,28,30,35, 0 };
int answer;

void solve(int now, int ret) {
	// 10�� ��� ���� ��� ���� ū ��.
	if (now == 10) {
		answer = max(answer, ret);
		return;
	}
	// �̵��ؾ� �� ĭ ��
	int go = dice[now];
	for (int i = 0; i < 4; i++) {
		// i��° ���� �̹� �����ߴٸ� �н�
		if (horse[i] > 31) continue;

		int next;	// i��° ���� ���� ��ġ
		int tmp = horse[i];

		// ���� ��ġ�� (10,20,30, 30�̻� �� ���)
		if ((horse[i] != 0 &&horse[i] % 5 == 0 )|| horse[i] >= 15) {
			next = kan[horse[i]];
			// �� ĭ�� ���� ĭ�� ��ġ�� Ȯ���ϸ� �̵�
			for (int j = 0; j < go-1; j++) {
				next = kan[next];
				// �� ���߿� �����ߴٸ�?
				if (next == -1)
					break;
			}
			// �����ߴٸ� �����ߴٰ� ǥ��
			if (next == -1) {
				next = 32;
			}
		}
		else {
			next = horse[i] + go;	// ������ ��Ÿ�� �̵�
		}
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			// ���� ���� ��ġ�� ���� �ֳ� Ȯ��
			if (next != 32 &&next == horse[j]) {
				flag = false;
				break;
			}
		}
		// ���� ���ٸ� �� ���ؼ� ��� ȣ��
		if (flag) {
			
			horse[i] = next;
			solve(now + 1, ret + score[next]);
			horse[i] = tmp;

		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++) {
		horse[i] = 0;
	}
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	answer = 0;
	solve(0, 0);
	cout << answer;
	
	return 0;
}