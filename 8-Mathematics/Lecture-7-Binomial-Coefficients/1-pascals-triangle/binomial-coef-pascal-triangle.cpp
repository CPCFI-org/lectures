#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Pascal's triangle

const int maxn = 100;
int C[maxn + 1][maxn + 1];

void pascal_triangle()
{
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n)
    {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}

int main()
{
    pascal_triangle();
    int n, k;
    cin >> n >> k;

    cout << C[n][k] << '\n';

    return 0;
}