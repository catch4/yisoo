// 백준 8980번 택배

// 풀이 실패 => 해설 참고

// 그리디 알고리즘
// 도착점, 시작점 순으로 오름차순 정렬
// 그 이후 남은 공간 생각해보면서 가능한 경우 체크.

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 2001

using namespace std;

struct Info {
    int start, end, box;

    bool operator<(const Info& info)
    {
        if (end == info.end)
            return start < info.start;
        return end < info.end;
    }
};

int c, m, n;
int stack[MAX];
vector<Info> arr;

void input()
{
    cin >> n >> c >> m;
    int start, end, box;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> box;
        arr.push_back({ start, end, box });
    }
}

int solve()
{
    int answer = 0;

    sort(arr.begin(), arr.end());

    for (Info info : arr) {
        int now = 0;
        int capacity = 0;
        for (int i = info.start; i < info.end; i++) {
            now = max(now, stack[i]);
        }

        capacity = min(info.box, c - now);
        answer += capacity;
        for (int i = info.start; i < info.end; i++) {
            stack[i] += capacity;
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();
    cout << solve();

    return 0;
}