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

int solve_congruence_eq(int a, int b, int n)
{
    int sol, x, y;
    int g = gcd(a, n, x, y);
    if (g == 1)
    {
        sol = b * mod_inverse_euclidean(a, n) % n;
        return sol;
    }
    else if (b % g == 0)
    {
        return solve_congruence_eq(a / g, b / g, n / g);
    }
    // No hay solución
    return 0;
}

int main()
{
    int a, b, m, x;
    cin >> a >> b >> m;
    x = solve_congruence_eq(a, b, m);

    cout << a << " * " << x << " = " << b << "  (mod " << m << ")" << '\n';

    return 0;
}