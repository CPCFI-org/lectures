#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int MAXN = 10000;
int m = 1000000007;
vector<int> factorial(MAXN + 1);

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

ll mod_inverse(int a, int m)
{
    int exp;
    exp = m - 2;

    return modular_binpow(a, exp, m);
}
//---------------------------------------------

void precomp_factorials()
{
    factorial[0] = 1;

    for (int i = 1; i <= MAXN; i++)
    {
        factorial[i] = factorial[i - 1] * i % m;
    }
}

ll binomial_coefficient(int n, int k)
{
    // cout << mod_inverse(factorial[k] * factorial[n - k] % m, m) << '\n';
    return factorial[n] * mod_inverse(factorial[k] * factorial[n - k] % m, m) % m;
}

int main()
{
    precomp_factorials();
    int n, k;
    cin >> n >> k;

    cout << binomial_coefficient(n, k) << '\n';

    return 0;
}