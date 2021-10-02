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

void debug(vector<int> A) {
    TR(x, A) {
        cout << x << " ";
    }
    cout << endl;
}

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

vector<long long> A;
vector<long long> ST;

void build(int n) { // O(n)
    for(int i = n; i < 2*n; i++) {
        ST[i] = A[i-n];
    }
    for (int i = n-1; i >= 1; i--) {
        ST[i] = ST[2*i] +  ST[2*i+1];
    }
}

long long T(int node, int i, int j, int L, int R) {
    if (L > j || R < i) return 0; //RMaxQ
    if (L >= i && R <= j) return ST[node];
    int M = (L+R)/2;
    return T(node*2, i, j, L, M) +  T(node*2+1, i, j, M+1, R);
}

void solve() {
    long long n, q;
    cin >> n >> q;
    FO(i, n) {
        long long e; cin >> e;
        A.push_back(e);
    }

    // si popcount(n) == 1: n es una potencia de dos
    // si popcount(n) != 1: n NO una potencia de dos
    while(__builtin_popcount(n) != 1) {
        A.push_back(0);
        n++;
    }

    FO(i, 2*n) ST.push_back(0);
    build(n);

    int L = 0; 
    int R = n-1;

    FO(k, q) {
        long long i, j;
        cin >> i >> j;
        i--;
        j--;
        cout << T(1, i, j, L, R) << endl;
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