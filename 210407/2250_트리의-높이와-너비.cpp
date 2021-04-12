// 백준 2250번 트리의-높이와-너비

// 재귀 +전역변수 이용해서 높이와 너비 구하기

/*
0. 루트 노드 구하기 =>부모가 없으면 루트.

1. base case : 방문할 대상이 없을 때
2. 방문 대상에서 왼쪽, 본인, 오른쪽 방문
3. 방문 대상은 높이 저장 및 현재 가장 왼쪽를 나타내는 변수 +1

*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 10002
#define left first
#define right second

using namespace std;
typedef pair<int, int> pi;

int n, v, l, r, mostLeft;
pi width[MAX];
pi node[MAX];
int depth;
bool check[MAX];
const int INF = 1e4 + 1;

void input()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v >> l >> r;
        node[v] = { l, r };
        if (l != -1)
            check[l] = true;
        if (r != -1)
            check[r] = true;
    }
}

int getRoot()
{
    for (int i = 1; i <= n; i++) {
        if (!check[i])
            return i;
    }
    return 0;
}

void visit(int cur, int h)
{
    if (cur == -1)
        return;
    depth = max(depth, h);
    visit(node[cur].left, h + 1);
    width[h] = { min(width[h].first, ++mostLeft), max(width[h].second, mostLeft) };
    visit(node[cur].right, h + 1);
}

pi solve()
{
    int root = getRoot();
    for (int i = 1; i <= n; i++) {
        width[i] = { INF, -1 };
    }
    visit(root, 1);

    int maxWidth = -1;
    int maxIdx = -1;
    for (int i = 1; i <= depth; i++) {
        int nowWidth = width[i].second - width[i].first + 1;
        if (maxWidth < nowWidth) {
            maxWidth = nowWidth;
            maxIdx = i;
        }
    }
    return { maxIdx, maxWidth };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();
    pi ret = solve();
    cout << ret.first << " " << ret.second;

    return 0;
}