#include <iostream>
#include <vector>
#include <algorithm>

// 백준 7453번 합이 0인 네 정수

using namespace std;

// n이 크지 않다면 브루트 포스 but, n이 4000이므로 N^2* logN^2 안으로 끝내야 한다. => 이분 탐색 활용
// 일단 두 그룹(a,b / c,d)으로 나눠 각 원소의 합을 배열에 저장. => 어차피 1+1+1+1 이나, 2+2이나 4인 것은 매한가지.
// a,b의 합을 기준으로 c,d의 합과의 총 합이 0인 경우를 이분탐색으로 찾는다.
// 찾을 때 중요한 건 answer의 값이 int범위를 넘어갈 수도 있다는 것과 각 그룹 중 합이 같은 것이 있을 수 있다. => upper_bound-lower_bound의 값이 중복값을 처리.

int n;

int main() {
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	vector<int> ab(n * n), cd(n * n);
	// 합 구하기.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab[i * n + j] = a[i] + b[j];
			cd[i * n + j] = c[i] + d[j];
		}
	}
	// cd는 정렬해야 이분탐색 가능.
	sort(cd.begin(), cd.end());

	long long answer = 0;
	for (int i = 0; i < n * n; i++) {
		int left = 0, right = n * n;

		// 이분탐색
		while (left < right) {
			int mid = (left + right) / 2;
			// 중복값 처리.
			if (ab[i] + cd[mid] == 0) {
				answer += upper_bound(cd.begin(), cd.end(), -ab[i]) - lower_bound(cd.begin(), cd.end(), -ab[i]);
				break;
			}
			else if (ab[i] + cd[mid] > 0) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
	}
	cout << answer << endl;
	return 0;
}