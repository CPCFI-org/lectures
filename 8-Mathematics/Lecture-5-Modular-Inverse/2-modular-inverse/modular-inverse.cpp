#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// modular binary exponentiation
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

// euler totient function
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result = result - result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll mod_inverse(int a, int m)
{
    int exp;
    exp = phi(m) - 1;

    return modular_binpow(a, exp, m);
}

int main()
{
    int a, m;
    cin >> a >> m;

    cout << mod_inverse(a, m) << '\n';

    return 0;
}
