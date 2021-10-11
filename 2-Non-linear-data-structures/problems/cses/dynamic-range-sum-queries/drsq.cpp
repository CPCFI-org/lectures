#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl                        '\n'
#define fastIO()                    cin.tie(0); cout.tie(0);
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& (v) : (arr))
#define debug(x)                    cout << #x << " = "; _debug(x); cout << endl;
#define si(x)	                    scanf("%d",&x)
#define sl(x)	                    scanf("%lld",&x)
#define pi(x)	                    printf("%d\n",x)
#define pl(x)	                    printf("%lld\n",x)
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end() 
#define sz(x)                       (int) x.size()
#define LB(arr, x)                  lower_bound(all(arr), x)-(arr).begin()
#define UB(arr, x)                  upper_bound(all(arr), x)-(arr).begin()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

template <typename T>
void _debug(T& x){
    cout << x;
}

template <typename T1, typename T2>
void _debug(pair<T1, T2>& pair){
    cout << "{"; _debug(pair.F); cout << ","; _debug(pair.S); cout << "}";  
}

template <typename T>
void _debug(vector<T>& vec){
    int n = sz(vec);
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    FO(i, n-1){
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n-1]); cout << "]";
}

void _debug(vector<string>& vec){
    int n = sz(vec);
    cout << endl;
    FO(i, n){
        cout << vec[i] << endl;
    }
}

template <typename T>
void _debug(vector<vector<T>>& A){
    int n = sz(A);
    cout << endl;
    FO(i, n){
        _debug(A[i]); cout << endl;
    }
}

template <typename T>
void print(T& x){
    cout << x << endl;
    return;
}

template <typename T>
void print(vector<T>& vec, int a=0, int b=-1){
    if(b == -1){b = sz(vec);}
    if(b == 0){return;}
    FOR(i, a, b-1){
        cout << vec[i] << " ";
    }
    cout << vec[b-1] << endl;
    return; 
}

// -----------------------------------------------------------------------------
// Solution starts here
// -----------------------------------------------------------------------------
vector<long long> A;
vector<long long> ST;

void build(int n) { // O(n)
    for(int i = n; i < 2*n; i++) {
        ST[i] = A[i-n];
    }
    for (int i = n-1; i >= 1; i--) {
        ST[i] = ST[2*i] + ST[2*i+1];
    }
}

long long T(int node, int i, int j, int L, int R) {
    if (L > j || R < i) return 0; //RMaxQ 1. 
    if (L >= i && R <= j) return ST[node]; // 2. 
    int M = (L+R)/2;
    return T(node*2, i, j, L, M) +  T(node*2+1, i, j, M+1, R); // 3.
}

void update(int pos, ll newVal, int n) {
    A[pos] = newVal;
    ST[pos+n] = newVal;
    ll i = (pos+n)/2;
    while (i > 0) {
        ST[i] = ST[2*i] + ST[2*i+1];
        i /= 2;
    }
}


void solve() {
    int n, q;
    cin >> n >> q;
    FO(i, n) {
        ll e; cin >> e;
        A.pb(e);
    }

    // debug(A);
    while(__builtin_popcount(n) != 1) {
        A.push_back(0);
        n++;
    }
    FO(i, 2*n) ST.pb(0);

    //1. 
    build(n);
    // debug(ST);

    //2. queries 
    int L = 0; 
    int R = n-1;
    FO(query_idx, q) {
        int d, k;
        ll u;
        cin >> d >> k >> u;
        if (d == 1) {
            k--;
            update(k, u, n);
        } else if (d == 2) {
            int i = k;
            int j = u;
            i--;
            j--;
            cout << T(1, i, j, L, R) << endl;
        }
    }
    
    return;
}

int main() {
    fastIO();
    if(getenv("LOCAL")){setIO();}
    int T=1;
    FO(i, T) {
        solve();
    }
    return 0;
}