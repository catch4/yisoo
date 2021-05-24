// 백준 13325번 이진-트리

/*
최대 값을 기준으로 남은 값을 계산. 
최소가 되려면 최대한 부모가 남은 값을 감당하도록 미뤄야 한다. 
=> 왼쪽/오른쪽 트리의 값 중 작은 값은 부모가 계산하도록 넘긴다.
=> 큰 값 - 작은 값은 자식이 감당.

*/

#include <iostream>

using namespace std;
typedef pair<int, int> pi;

int k;
int arr[2 << 21], sum[2 << 21], diff[2 << 21];
int answer = 0;

void input()
{
    cin >> k;
    for (int i = 1; i < (1 << (k + 1)) - 1; i++) {
        cin >> arr[i];
        answer += arr[i];
    }
}

int getParent(int cur)
{
    return (cur - 1) / 2;
}

pi getChild(int cur)
{
    return { cur * 2 + 1, cur * 2 + 2 };
}

void goDown(int parent, int cur)
{
    if (cur > ((1 << (k + 1)) - 2))
        return;

    sum[cur] = arr[cur] + sum[parent];

    pi child = getChild(cur);
    goDown(cur, child.first);
    goDown(cur, child.second);
}

int getMax()
{
    int ret = -1;
    for (int i = (1 << k) - 1; i < (1 << (k + 1)) - 1; i++) {
        ret = max(ret, sum[i]);
    }
    return ret;
}

void goUp()
{
    int maxVal = getMax();

    for (int i = (1 << k) - 1; i < (1 << (k + 1)) - 1; i++) {
        diff[i] = maxVal - sum[i];
    }

    for (int i = k; i > 0; i--) {
        int start = (1 << i) - 1;
        int end = (1 << (i + 1)) - 1;

        for (int j = start; j < end; j += 2) {
            int p = getParent(j);
            int minVal = min(diff[j], diff[j + 1]);
            diff[p] = minVal;

            answer += max(diff[j], diff[j + 1]) - minVal;
        }
    }
    return;
}

void solve()
{
    goDown(0, 0);
    goUp();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    cout << answer;

    return 0;
}