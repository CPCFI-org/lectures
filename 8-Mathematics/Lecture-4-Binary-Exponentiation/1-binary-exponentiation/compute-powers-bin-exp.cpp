#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) // check if the last bit of b is 1
            res = res * a;
        a = a * a;
        b >>= 1; // right shift
    }
    return res;
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << binpow(a, n) << '\n';

    return 0;
}