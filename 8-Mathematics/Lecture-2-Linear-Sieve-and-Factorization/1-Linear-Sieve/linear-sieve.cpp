#include <bits/stdc++.h>
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

int main()
{
    LinearSieve();
    int m;
    cin >> m;

    cout << lp[m] << '\n';
    return 0;
}
