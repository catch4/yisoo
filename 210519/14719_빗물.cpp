// 백준 14719번 빗물

// 단순 구현. O(2N)

#include <iostream>

using namespace std;

int w, h, arr[501];
int answer;

void input()
{
    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        cin >> arr[i];
    }
}

int cal(int l, int r, int val)
{
    int sum = 0;
    for (int i = l + 1; i < r; i++) {
        sum += val - arr[i];
    }
    return sum;
}

void go(int start)
{
    if (start >= w - 1)
        return;
    int now = start + 1;
    int secondMaxHeight = -1;
    int secondMaxIdx = start;
    while (arr[now] < arr[start] && (now < w)) {
        if (secondMaxHeight < arr[now]) {
            secondMaxHeight = arr[now];
            secondMaxIdx = now;
        }
        now++;
    }

    int idx = now == w ? secondMaxIdx : now;
    int val = now == w ? secondMaxHeight : arr[start];

    answer += cal(start, idx, val);

    go(idx);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    go(0);
    cout << answer;
    return 0;
}