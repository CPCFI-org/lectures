#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << binpow(a, n) << '\n';

    return 0;
}
