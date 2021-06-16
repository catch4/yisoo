// 백준 17406번 배열-돌리기4

#include <cstring>
#include <iostream>
#include <string>

#define MAX 51
using namespace std;

struct cmd {
    int r, c, s;
};

int arr[MAX][MAX];
int temp[MAX][MAX];
int n, m, k;
cmd command[6];
bool check[6];
int answer = 1e9;

void rotate(cmd turn)
{
    if (turn.s == 0)
        return;
    int x1 = turn.r - turn.s - 1, y1 = turn.c - turn.s - 1;
    int x2 = turn.r + turn.s - 1, y2 = turn.c + turn.s - 1;

    int val = temp[x1][y1];

    // left side
    for (int i = x1 + 1; i <= x2; i++) {
        temp[i - 1][y1] = temp[i][y1];
    }
    // down side
    for (int i = y1 + 1; i <= y2; i++) {
        temp[x2][i - 1] = temp[x2][i];
    }
    // right side
    for (int i = x2 - 1; i >= x1; i--) {
        temp[i + 1][y2] = temp[i][y2];
    }
    // upside
    for (int i = y2 - 1; i >= y1; i--) {
        temp[x1][i + 1] = temp[x1][i];
    }
    temp[x1][y1 + 1] = val;

    // 한 칸 안 정사각형 회전
    turn.s -= 1;
    rotate(turn);
}

int calLowestSumOfRow()
{
    int result = 1e9;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temp[i][j];
        }
        result = min(sum, result);
    }
    return result;
}

void permutation(string order)
{
    if (order.size() == k) {
        memcpy(temp, arr, sizeof(arr));
        for (char c : order) {
            int idx = c - '0';
            rotate(command[idx]);
        }
        answer = min(answer, calLowestSumOfRow());
        return;
    }
    for (int i = 0; i < k; i++) {
        if (!check[i]) {
            check[i] = true;
            permutation(order + to_string(i));
            check[i] = false;
        }
    }
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < k; i++)
        cin >> command[i].r >> command[i].c >> command[i].s;
}

int main()
{
    input();
    permutation("");
    cout << answer;

    return 0;
}