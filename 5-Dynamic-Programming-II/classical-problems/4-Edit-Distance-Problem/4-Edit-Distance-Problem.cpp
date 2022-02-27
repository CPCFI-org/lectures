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

/*
Edit Distance Problem
- Given two strings s1,s2,...,sn and t1,t2,...,tm
- Three operations are allowed:
    1. Insert any letter to s at cost a
    2. Remove any letter from s at cost d 
    3. Replace any letter with some other one at cost r
- Start with s and end up with t at the minimum cost
*/

int edit_distance(const string & s, const string & t, int a, int d, int r) {
    int n = (int)s.size();
    int m = (int)t.size();
    vector<vector<int>> f(n+1, vector<int>(m+1, INF));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                f[i][j] = 0;
            } else {
                if (i > 0) f[i][j] = min(f[i][j], f[i-1][j] + d);
                if (j > 0) f[i][j] = min(f[i][j], f[i][j-1] + a);
                if (i > 0 && j > 0) {
                    int z = 0;
                    if (s[i] != t[j]) z = r;
                    f[i][j] = min(f[i][j], f[i-1][j-1]+z);
                }
            }
        }
    }
    debug(f);
    return f[n][m];
}

void solve() {
    int a, d, r;
    cin >> a >> d >> r;
    string s, t;
    cin >> s >> t;
    auto cost = edit_distance(s, t, a, d, r);
    cout << cost << endl;
    return;
}

int main() {
    fastIO();
    if(getenv("LOCAL")){setIO();}
    int T = 1;
    FO(i, T) {
        solve();
    }
    return 0;
}