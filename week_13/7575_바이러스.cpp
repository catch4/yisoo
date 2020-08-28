// 백준 7575번 바이러스
/*
접근 : 
문자열 검색 =>KMP이용

풀이 :
1 .프로그램 길이가 제일 짧은 것을 기준으로 문자열 생성
+
2. 모든 프로그램에 대해 앞 뒤 뒤집기를 모두 검색

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int p[101][1001];
int len[101];

// tmp[ : i] 중 접두사, 접미사가 같으며 가장 긴 문자열 = pi[i]
vector<int> getPi(vector<int> tmp) {
	int size = tmp.size();
	vector<int> pi(size, 0);

	int begin = 1, matched = 0;
	while (begin + matched < size) {
		if (tmp[begin + matched] == tmp[matched]) {
			matched++;
			pi[begin+ matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

// 모든 프로그램에 대해 tmp 검색
bool kmp(vector<int> tmp, vector<int> pi) {
	int size = tmp.size();

	// 프로그램 1부터 n까지 앞뒤 검색
	for (int i = 0; i < n; i++) {
		// 정방향 배열 검색
		int begin = 0, matched = 0;
		bool flag = false;
		while (begin <= len[i] - size) {
			if (matched < size && (p[i][begin + matched] == tmp[matched])) {
				matched++;
				if (matched == size) {
					// 찾을 경우
					flag = true;
					break;
				}
			}
			else {
				if (matched == 0)
					begin++;
				else {
					begin += matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		// 찾았을 경우 다음 프로그램 검색
		if (flag) continue;

		// 뒤집어서 검색
		reverse(tmp.begin(), tmp.end());
		begin = 0, matched = 0;
		while (begin <= len[i] - size) {
			if (matched < size && (p[i][begin + matched] == tmp[matched])) {
				matched++;
				if (matched == size) {
					flag = true;
					break;
				}
			}
			else {
				if (matched == 0)
					begin++;
				else {
					begin += matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		// 뒤집어서도 못 찾은 경우는 바이러스 없음.
		if (!flag) return false;
	}
	// 모두 바이러스 있다.
	return true;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	int minLen = 1000;
	int minIdx = 0;
	for (int i = 0; i < n; i++) {
		cin >> len[i];
		if (minLen > len[i]) {
			minIdx = i;
			minLen = len[i];
		}
		for (int j = 0; j < len[i]; j++) 
			cin >> p[i][j];
	}

	for (int j = 0; j <= len[minIdx] - k; j++) {
		// 1. 제일 짧은 프로그램 기준으로 배열 생성
		vector<int> tmp;
		for (int a = j; a < j + k; a++) {
			tmp.push_back(p[minIdx][a]);
		}
		vector<int> pi = getPi(tmp);
		// 모든 프로그램에 있다면 종료
		if (kmp(tmp,pi)) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";


	return 0;
}