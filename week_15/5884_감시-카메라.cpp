// ���� 5884�� ����ī�޶�

/*
������� ����� ����. 
1. line�� ��� ��ǥ�� Ŀ���ؾ� �Ѵ�.
2. line�� �ִٸ� �״�� ��� ȣ��
3. ���ٸ� x = a, y= b �ϳ��� ���� �־ ��� ȣ��
4. line�� ũ�Ⱑ 3�� ���� �ʰ�, idx�� n���� �´ٸ� �̴� ������ ��.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
int n;

vector<pi> arr;
bool answer;

void go(int idx, vector<pi> line)
{
    if (line.size() > 3)
        return;
    if (idx == n) {
        answer = 1;
        return;
    }

    bool flag = false;
    for (int j = 0; j < line.size(); j++) {
        int x = line[j].first, y = line[j].second;
        if ((x == -1 && y == arr[idx].second) || (y == -1 && x == arr[idx].first)) {
            go(idx + 1, line);
            return;
        }
    }
    if (!flag) {
        line.push_back({ -1, arr[idx].second });
        go(idx + 1, line);
        line.pop_back();
        line.push_back({ arr[idx].first, -1 });
        go(idx + 1, line);
        line.pop_back();
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr.push_back({ x, y });
    }

    go(0, {});

    cout << answer;
    return 0;
}