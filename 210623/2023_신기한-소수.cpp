// 백준 2023번 신기한-소수

// 소수는 2를 제외하고 홀수다!

#include <iostream>
#include <vector>
using namespace std;

int n;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void solve(int num, int count)
{
    if (count == n) {
        cout << num << "\n";
        return;
    }

    for (int i = 1; i <= 9; i += 2) {
        if (isPrime(num * 10 + i))
            solve(num * 10 + i, count + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    int arr[4] = { 2, 3, 5, 7 };
    for (int val : arr) {
        solve(val, 1);
    }

    return 0;
}