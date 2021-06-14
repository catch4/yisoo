// 백준 14676번 영우는-사기꾼

// 위상정렬

#include <iostream>
#include <string>
#include <vector>
#define MAX 100001

using namespace std;
typedef pair<int, int> pi;

int n, m, k, x, y;

vector<int> node[MAX];
int point[MAX];
int countOfBuilding[MAX];
vector<pi> command;

const string KING = "King-God-Emperor";
const string LIER = "Lier!";

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        node[x].push_back(y);
        point[y]++;
    }

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        command.push_back({ x, y });
    }
}

// 건설
bool build(int num)
{
    if (point[num] != 0)
        return false;

    countOfBuilding[num]++;

    if (countOfBuilding[num] == 1) {
        for (int adj : node[num])
            point[adj]--;
    }
    return true;
}

// 파괴
bool destroy(int num)
{
    if (countOfBuilding[num] == 0)
        return false;

    countOfBuilding[num]--;

    if (countOfBuilding[num] == 0) {
        for (int adj : node[num]) {
            point[adj]++;
        }
    }

    return true;
}

bool doCommand(int operation, int number)
{
    if (operation == 1)
        return build(number);
    return destroy(number);
}

string solve()
{
    for (pi cmd : command) {
        if (!doCommand(cmd.first, cmd.second))
            return LIER;
    }
    return KING;
}

int main()
{
    input();
    cout << solve();
    return 0;
}