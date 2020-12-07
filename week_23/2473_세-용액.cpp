// 백준 2473번 세 용액

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n;
ll arr[5001];
vector<int> ans;
ll minVal = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int start = 0, end = n - 1;
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int s = i + 1, e = n - 1;

        while (s < e) {
            ll sum = arr[i] + arr[s] + arr[e];

            if (llabs(sum) < llabs(minVal)) {
                ans = { i, s, e };
                minVal = sum;
            }

            if (sum > 0)
                e--;
            else
                s++;
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << arr[ans[i]] << " ";
    }
    return 0;
}