// 백준 2623번 음악프로그램

// 위상정렬 + 사이클인 경우 n개가 없을테니까 판정

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int p[1001];
vector<int> go[1001];
vector<int> ans;

void tpsort()
{
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int from = q.front();
        q.pop();
        ans.push_back(from);
        for (int to : go[from]) {
            p[to]--;
            if (p[to] == 0) {
                q.push(to);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int num;
    for (int i = 0; i < m; i++) {
        cin >> num;
        vector<int> tmp(num);
        for (int j = 0; j < num; j++) {
            cin >> tmp[j];
        }

        for (int j = 0; j < num - 1; j++) {
            int a = tmp[j], b = tmp[j + 1];
            go[a].push_back(b);
            p[b]++;
        }
    }

    tpsort();

    if (ans.size() != n) {
        cout << 0;
    } else {
        for (int i = 0; i < n; i++)
            cout << ans[i] << "\n";
    }

    return 0;
}