// 백준 17135번 캐슬-디펜스

/*
15C3이므로 완전탐색

1. 궁수 위치 조합
2. 궁수 위치에 따라 최대 제거할 수 있는 적 계산
    - 궁수 위치마다 가까운 적 찾기 => 모든 위치마다 가까운 애들부터 찾아서 정렬
    - 찾은 적 제거
    - 궁수 위치를 올려서 진행

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
struct dist {
    int c, x, y;
};

int n, m, d;
int map[16][16];
bool v[16];
int ans;
vector<dist> arr[3];

bool cmp(dist a, dist b)
{
    if (a.c == b.c) {
        return a.y < b.y;
    }
    return a.c < b.c;
}

int calcRemove(vector<int> archer)
{
    int cnt = 0;

    vector<vector<bool>> copyMap(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copyMap[i][j] = map[i][j];
        }
    }

    for (int archerRow = n; archerRow > 0; archerRow--) {

        for (int i = 0; i < 3; i++) {
            arr[i].clear();
            int archerCol = archer[i];

            for (int row = archerRow - 1; row >= max(0, archerRow - d); row--) {
                for (int col = 0; col < m; col++) {
                    if (copyMap[row][col]) {
                        int cost = abs(archerRow - row) + abs(archerCol - col);
                        if (cost <= d)
                            arr[i].push_back({ cost, row, col });
                    }
                }
            }
            sort(arr[i].begin(), arr[i].end(), cmp);
        }
        set<pi> countOfRemover;
        for (int i = 0; i < 3; i++) {
            if (arr[i].size() == 0)
                continue;
            int nx = arr[i][0].x, ny = arr[i][0].y;

            copyMap[nx][ny] = 0;
            countOfRemover.insert({ nx, ny });
        }
        cnt += countOfRemover.size();
    }

    return cnt;
}

void dfs(int num, vector<int> arr)
{
    if (arr.size() == 3) {
        ans = max(ans, calcRemove(arr));
        return;
    }

    for (int i = num; i < n; i++) {
        if (!v[i]) {
            v[i] = 1;
            arr.push_back(i);
            dfs(i, arr);
            arr.pop_back();
            v[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    dfs(0, {});

    cout << ans;

    return 0;
}