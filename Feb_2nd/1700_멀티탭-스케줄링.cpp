// 백준 1700번 멀티탭-스케줄링

/*
1. 바꿔야할 때 뒤에서 제일 늦게 나오는 수를 대체
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, k;
int arr[101];
vector<int> plug;
unordered_map<int, vector<int>> m;
bool check[101];

// 플러그 꽂힌 수의 제일 최근에 나오는 index 찾아내기.
int getIdx(int idx, int val)
{
    // val보다 큰 인덱스 중에 가장 가까운 수 골라내기 위해 lowerbound 사용
    auto ret = lower_bound(m[plug[idx]].begin(), m[plug[idx]].end(), val) - m[plug[idx]].begin();

    if (ret == m[plug[idx]].size())
        return 1001;

    return m[plug[idx]][ret];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        m[arr[i]].push_back(i); // 해당 숫자가 나오는 index 저장
    }

    if (n >= k) {
        cout << 0;
        return 0;
    }

    int empty = n;
    int ans = 0;

    for (int i = 0; i < k; i++) {
        if (check[arr[i]])
            continue;

        // 멀티탭 비었으면
        if (empty != 0) {

            plug.push_back(arr[i]);
            check[arr[i]] = 1;
            empty--;
        } else { // 플러그 뽑아야 할 때

            int val = -1;
            int minIdx = -1;
            // index가 제일 높은 수 골라내기
            for (int idx = 0; idx < n; idx++) {
                int tmp = getIdx(idx, i);
                if (tmp > val) {
                    val = tmp;
                    minIdx = idx;
                }
            }
            // 고른 숫자 대체하기
            check[plug[minIdx]] = 0;
            check[arr[i]] = 1;

            plug[minIdx] = arr[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}