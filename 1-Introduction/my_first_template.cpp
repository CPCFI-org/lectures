#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define pint(x)         printf("%d\n", x);
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);


int main() {
    int a; si(a);
    int b; si(b);
    cout << "Testing our template" << endl;
    pint(a);
    pint(b);
    cout << "Testing our FOR macro" << endl;
    FOR(i, a, b) {
        cout << i << endl;
    }
}