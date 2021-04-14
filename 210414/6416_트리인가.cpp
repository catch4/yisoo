// 백준 6416번 트리인가

/*
단순 구현.
들어오는 간선 갯수로 2개이상이면 false
들어오는 간선이 하나도 없는 노드가 2개이상이면 false

중요한건 데이터가 없어도 트리로 성립.
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

vector<pi> node;

bool input()
{
    int a, b;

    node.clear();

    while (true) {
        cin >> a >> b;

        if (a == 0 && b == 0)
            return true;
        else if (a == -1 && b == -1)
            return false;
        node.push_back({ a, b });
    }
}

bool isTree()
{
    if (node.size() == 0)
        return true;
    unordered_map<int, int> child;
    for (pi c : node) {
        if (child[c.second])
            return false;
        child[c.second]++;
    }

    set<int> root;
    for (pi c : node) {

        if (!child[c.first]) {
            root.insert(c.first);
        }
    }

    return root.size() == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num = 1;
    while (true) {

        bool in = input();
        if (in == false)
            break;
        bool result = isTree();
        if (result) {
            cout << "Case " << num << " is a tree.\n";
        } else {
            cout << "Case " << num << " is not a tree.\n";
        }
        num++;
    }

    return 0;
}