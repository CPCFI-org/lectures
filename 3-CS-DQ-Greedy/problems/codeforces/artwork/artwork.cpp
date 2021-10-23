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
int m, n, k;
const int MAXN = 1001;
vi P(MAXN);

struct circle {
    ll x, y, r;
} sensors[MAXN];

int findParent(int x) {
    return P[x] == x ? x : P[x] = findParent(P[x]);
}

bool check_corners(circle c1, circle c2) {
    if (c1.x - c1.r > 0 && c1.y+c1.r < n) return false;
    if (c2.x + c2.r < m && c2.y - c2.r > 0) return false;
    return true;
}


bool circles_intersect(circle c1, circle c2) {
    ll d = pow(c1.x-c2.x, 2) + pow(c1.y-c2.y, 2);
    return d <= pow(c1.r, 2) + pow(c2.r, 2) + 2*c1.r*c2.r;
}


void solve() {
    si(n); si(m); si(k);
    FOR(i, 1, k+1) {
        scanf("%lld%lld%lld", &sensors[i].x, &sensors[i].y, &sensors[i].r);
        P[i] = i; //Parents
    }

    FOR(i, 1, k+1) {
        FOR(j, 1, k+1) {
            if (circles_intersect(sensors[i], sensors[j])) {
                int pc1 = findParent(i);
                int pc2 = findParent(j);
                // Union
                if (pc1 != pc2) P[pc1] = pc2;
            }
        }
    }

    bool cuts = false;
    FOR(i, 1, k+1) {
        FOR(j, 1, k+1) {
            circle c1 = sensors[i];
            circle c2 = sensors[j];
            if (check_corners(c1, c2) && P[i] == P[j]){
                cuts = true;
            }
        }
    }
    cuts ? cout << "N\n" : cout << "S\n";
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