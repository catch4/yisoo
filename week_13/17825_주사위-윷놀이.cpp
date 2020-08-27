// 백준 17825번 주사위 윷놀이

/*
접근 : 
Turn마다 가능한 경우는 4^10이므로 브루트포스 가능 + 백트래킹으로 경우 줄이기.

풀이 :
1. 발판?마다 갈 수 있는 경우는 고정됨 => 배열로 발판마다 다음 발판의 위치를 표시
2. dice[now]을 더했을 때 위치에 다른 말이 있다면 pass
3. 다른 말 없다면 해당 점수 더하고 재귀호출
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dice[10];		// 주사위
int horse[4];		// 말의 위치
// 칸이 가야할 다음 위치.
int kan[33] = { 	1,2,3,4,5,	21,7,8,9,10,	24, 12,13,14,15,	29,17,18,19,20,	32, 22, 23, 26, 25,	26, 30, 26, 27, 28,	31,	20, -1 };
int score[33] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,22,24,25,26,27,28,30,35, 0 };
int answer;

void solve(int now, int ret) {
	// 10번 모두 했을 경우 제일 큰 값.
	if (now == 10) {
		answer = max(answer, ret);
		return;
	}
	// 이동해야 할 칸 수
	int go = dice[now];
	for (int i = 0; i < 4; i++) {
		// i번째 말이 이미 도착했다면 패스
		if (horse[i] > 31) continue;

		int next;	// i번째 말의 도착 위치
		int tmp = horse[i];

		// 말의 위치가 (10,20,30, 30이상 일 경우)
		if ((horse[i] != 0 &&horse[i] % 5 == 0 )|| horse[i] >= 15) {
			next = kan[horse[i]];
			// 한 칸씩 다음 칸의 위치를 확인하며 이동
			for (int j = 0; j < go-1; j++) {
				next = kan[next];
				// 그 와중에 도착했다면?
				if (next == -1)
					break;
			}
			// 도착했다면 도착했다고 표시
			if (next == -1) {
				next = 32;
			}
		}
		else {
			next = horse[i] + go;	// 빨간색 줄타고 이동
		}
		bool flag = true;
		for (int j = 0; j < 4; j++) {
			// 말의 도착 위치에 누가 있나 확인
			if (next != 32 &&next == horse[j]) {
				flag = false;
				break;
			}
		}
		// 누가 없다면 값 더해서 재귀 호출
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