#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

const int sieve_size = 10000000;
vector<int> lp(sieve_size + 1, 0);
vector<int> pr;

void LinearSieve()
{
    for (int i = 2; i <= sieve_size; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= sieve_size; ++j)
        {
            lp[i * pr[j]] = pr[j];
        }
    }
}

vector<ll> trial_division(ll n)
{
    vector<ll> factorization;
    for (ll d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

vector<long long> trial_division_primes(long long n)
{
    vector<long long> factorization;
    for (long long d : pr)
    {
        if (d * d > n)
            break;
        while (n % d == 0)
        {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

vector<long long> factors_sieve(long long n)
{
    vector<long long> factorization;
    while (n > 1)
    {
        factorization.push_back(lp[n]);
        n /= lp[n];
    }
    return factorization;
}

int main()
{
    ll m;
    cin >> m;
    LinearSieve();
    vector<ll> prime_factors = trial_division(m);
    vector<ll> prime_factors_2 = trial_division_primes(m);
    vector<ll> prime_factors_3 = factors_sieve(m);

    for (int i = 0; i < prime_factors_3.size(); i++)
    {
        cout << prime_factors_3[i] << ", ";
    }
    cout << '\n';
    return 0;
}