// 백준 17352번 여러분의-다리가 되어 드리겠습니다!

// union-find

#include <iostream>
#define MAX 300001

using namespace std;

int n;
int p[MAX];

int find(int cur)
{
    if (p[cur] == cur)
        return cur;
    return p[cur] = find(p[cur]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int a, b;
    for (int i = 0; i < n - 2; i++) {
        cin >> a >> b;
        int x = find(a), y = find(b);
        if (x == y)
            continue;
        if (x > y)
            swap(x, y);
        p[y] = x;
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            cout << i << " ";
        }
    }

    return 0;
}