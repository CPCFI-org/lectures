#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll x)
{
    if (x <= 1)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;
    for (ll d = 3; d * d <= x; d += 2)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main()
{
    ll m;
    cin >> m;

    cout << isPrime(m) << '\n';
    return 0;
}