// 백준 1700번 멀티탭-스케줄링

/*
1. 모든 숫자의 빈도수 계산
2. 칸마다 제일 적은 빈도수를 빼기.


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

int getIdx(int idx, int val)
{
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
        m[arr[i]].push_back(i);
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
        if (empty != 0) {

            plug.push_back(arr[i]);
            check[arr[i]] = 1;
            empty--;
        } else {

            int val = -1;
            int minIdx = -1;
            for (int idx = 0; idx < n; idx++) {
                int tmp = getIdx(idx, i);
                if (tmp > val) {
                    val = tmp;
                    minIdx = idx;
                }
            }
            //cout << i << " " << plug[minIdx] << " " << arr[i] << endl;
            check[plug[minIdx]] = 0;
            check[arr[i]] = 1;

            plug[minIdx] = arr[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}