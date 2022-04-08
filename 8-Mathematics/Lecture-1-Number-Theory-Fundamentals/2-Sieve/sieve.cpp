#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sieve_size = 100000 - 1;
vector<bool> prime(sieve_size + 1, true);

void SieveOfEratosthenes()
{
    prime[0] = false;
    prime[1] = false;

    for (ll p = 2; p * p <= sieve_size; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= sieve_size; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    // for (int p = 2; p <= sieve_size; p++)
    //    if (prime[p])
    //        cout << p << " ";
}

int main()
{
    SieveOfEratosthenes();
    ll m;
    cin >> m;

    cout << prime[m] << '\n';
    return 0;
}