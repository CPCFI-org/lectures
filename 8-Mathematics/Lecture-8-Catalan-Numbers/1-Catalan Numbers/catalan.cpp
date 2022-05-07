#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int MAX = 100;
vector<int> catalan(MAX, 0);

void comp_catalan()
{
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= MAX; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
        {
            catalan[i] += (catalan[j] * catalan[i - j - 1]) % MOD;

            if (catalan[i] >= MOD)
            {
                catalan[i] -= MOD;
            }
        }
    }
}

int main()
{
    comp_catalan();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << catalan[i] << '\n';
    }

    return 0;
}
