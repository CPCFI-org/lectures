#include <bits/stdc++.h>
using namespace std;

#define fastIO          cin.tie(0); cout.tie(0);
#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x);
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);
#define all(x)          x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void setIO() {
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string input_file = file + "in";
    string output_file = file + "out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;

void solve() {
    string m;
    int q, p;
    cin >> m;
    while (strcmp(m.c_str(), "#") != 0) {
        si(q); si(p);
        pq.push(make_pair(p, make_pair(q, p)));
        cin >> m;
    }

    int K; si(K);
    while (K--) {
        // <600, <2004, 200>>
        pair<int, ii> p = pq.top(); pq.pop();
        cout << p.second.first << endl;
        p.first += p.second.second;
        pq.push(p);
    }

}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}