#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int mod_inverse_euclidean(int a, int m)
{
    int x, y;
    int g = gcd(a, m, x, y);
    if (g != 1)
    {
        return -1;
    }
    else
    {
        x = (x % m + m) % m; // make sure x is positive mod m
        return x;
    }
}

int main()
{
    int a, b, x, y, g;
    cin >> a >> b;

    g = gcd(a, b, x, y);
    cout << a << " * " << x << " + " << b << " * " << y << " = " << g << '\n';

    return 0;
}