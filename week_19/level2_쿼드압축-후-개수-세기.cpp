// 프로그래머스 level2 쿼드압축 후 개수 세기

// 분할 정복

#include <string>
#include <vector>

using namespace std;

vector<int> answer;

void split(vector<vector<int>>& arr, int x, int y, int size)
{
    int val = arr[x][y];
    bool flag = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != val) {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        answer[val]++;
    else {
        split(arr, x, y, size / 2);
        split(arr, x + size / 2, y, size / 2);
        split(arr, x, y + size / 2, size / 2);
        split(arr, x + size / 2, y + size / 2, size / 2);
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    for (int i = 0; i < 2; i++)
        answer.push_back(0);
    int n = arr.size();
    split(arr, 0, 0, n);

    return answer;
}