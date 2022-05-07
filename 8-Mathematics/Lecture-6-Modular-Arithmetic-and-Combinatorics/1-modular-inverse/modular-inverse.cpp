#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// This algorithm only works when m is prime
vector<int> every_modular_inverse(int m)
{
    vector<int> inv(m, 0);
    inv[1] = 1;

    for (int i = 2; i < m; ++i)
        inv[i] = m - (m / i) * inv[m % i] % m;
    return inv;
}

int main()
{
    int m;
    cin >> m;
    vector<int> inv = every_modular_inverse(m);

    for (int i = 1; i < m; i++)
    {
        cout << "El inverso de " << i << " es: " << inv[i] << '\n';
    }
    return 0;
}