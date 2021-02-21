// 백준 11758번 CCW

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x[3], y[3];

    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    int a = x[0] * y[1] + x[1] * y[2] + x[2] * y[0];
    int b = x[1] * y[0] + x[2] * y[1] + x[0] * y[2];

    if (a - b < 0) {
        cout << -1;
    } else if (a - b > 0) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}