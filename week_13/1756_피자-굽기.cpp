// 백준 1756번 피자굽기

/*
접근 :
0. O(n^2)으로 완전 탐색하면 시간 초과 => 
1. O(nlogn)으로 해결해보자
=> O(nlogn)은 이분탐색 사용,
-> 피자 반죽은 순서가 정해져있으므로 오븐에 대해 정렬 + 피자 지름이 처음 나오는 곳을 찾아서 이보다 작은 오븐 지름 중 깊이가 가장 얕은 곳 탐색
-> 구현의 어려움 + 시간 초과 우려 (이분 탐색 이후 다시 완전 탐색이므로)
-> 포기

2. O(n) 해결
-> O(n)의 경우 대부분 스택을 사용해 풀이
-> 따라서 이전에 풀이한 3015번 오아시스 재결합 과 유사한 풀이 생각.

풀이 방법 :
1. 조건은 오븐 지름이 피자 지름보다 작으면 피자는 그보다 위에 쌓인다.
2. 즉, 지금까지의 가장 작은 오븐 지름보다 작은 피자 반죽만 들어갈 수 있다.
3. 따라서 n-1번째 까지 작은 오븐 지름 min과 n 번째 지름 중 작은 값을 지름[n]번째에 저장
4. 피자 반죽을 오븐 가장 깊은 곳 부터 탐색

*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int D, N;
int d[300001], n[300001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> D >> N;
	
	int m = INT_MAX;
	for (int i = 1; i <= D; i++) {
		int t;
		cin >> t;
		m = min(m, t);	// 3.
		d[i] = m;			// 3.
	}
	for (int i = 0; i < N; i++) 
		cin >> n[i];

	int idx = 0;	// 현재 피자 반죽의 인덱스
	int now = D;
	for (int i = D; i >= 1;i--) {
		// 오븐 지름보다 피자 지름이 크면 못 들어가므로 pass
		if (d[i] < n[idx])
			continue;
		else {
			// 피자 지름이 더 작은 경우 안착
			now = i;
			idx++;
		}
		// 피자가 다 들어갔으면 끝
		if (idx == N)
			break;
	}
	// 피자가 다 안들어갔으면 불가.
	if (idx < N)
		cout << 0;
	else
		cout << now;


	return 0;
}