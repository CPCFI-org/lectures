#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modular_binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int a, n, m;
    cin >> a >> n >> m;

    cout << modular_binpow(a, n, m) << '\n';

    return 0;
}