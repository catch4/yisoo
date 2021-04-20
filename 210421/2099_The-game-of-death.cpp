// 백준 2099번 The game of death

// 비슷하게 풀이는 생각해냈으나 실패
// 분할정복을 이용한 행렬 거듭제곱

#include <iostream>
#include <vector>

#define MAX 201
using namespace std;

struct Matrix {
    int size;
    vector<vector<bool>> arr;

    Matrix(int s)
    {
        size = s;
        arr = vector<vector<bool>>(s, vector<bool>(s));
    }

    Matrix operator*(const Matrix& a)
    {
        Matrix ret(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    if (arr[i][k] && a.arr[k][j])
                        ret.arr[i][j] = 1;
                }
            }
        }
        return ret;
    }
};

int n, k, m;

Matrix pow(Matrix a, int p)
{
    if (p == 1)
        return a;
    Matrix ret = pow(a, p / 2);
    ret = ret * ret;
    if (p % 2)
        ret = ret * a;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> m;
    int a, b;
    Matrix path(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        path.arr[i][a - 1] = path.arr[i][b - 1] = 1;
    }

    Matrix ret = pow(path, k);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (ret.arr[a - 1][b - 1])
            cout << "death\n";
        else
            cout << "life\n";
    }

    return 0;
}