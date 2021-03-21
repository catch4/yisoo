// 백준 10800번 컬러볼

// 정렬 후 크기가 작은 경우만 체크

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 200001

using namespace std;

struct Ball {
    int num, color, size;

    bool operator<(const Ball& ball)
    {
        return size < ball.size;
    }
};

int n, c, s;
vector<Ball> arr;
int sumOfSize[MAX], cnt[MAX], lastNumCount[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> c >> s;

        arr.push_back({ i, c, s });
    }
    sort(arr.begin(), arr.end());
    int totalSum = 0;
    int maxVal = 0, maxCnt = 0;

    int idx = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i].num, color = arr[i].color, size = arr[i].size;

        while (arr[idx].size < size) {
            totalSum += arr[idx].size;
            sumOfSize[arr[idx].color] += arr[idx].size;

            idx++;
        }

        cnt[num] = totalSum - sumOfSize[color];
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << "\n";
    }

    return 0;
}