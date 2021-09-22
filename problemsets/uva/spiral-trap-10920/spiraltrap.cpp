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

//------------------------------------------------------------

void solve(int sz, int P){

    // 1. Nivel

    int level = (int)ceil(sqrt(P));
    
    if (level % 2 == 0) {
        level += 1;
    }

    int k = level - 1;
    int D = sz - level;

    // 2. Esquinas

    // esq. sup. der
    int esd = level*level;

    // esq sup izq
    int esi = level*level - 3*k;

    // esq. inf. der
    int eid = level*level - k;

    // esq inf izq
    int eii = level*level -2*k;

    // debug(level);
    // debug(k);
    // debug(esd);
    // debug(esi);
    // debug(eid);
    // debug(eii);

    // debug(P);

    // 3. Rango
    int diff;
    int L, C; //L: Linea, C: columna
    if (P < esi) { // renglón superior
        L = level;
        C = 1 + (esi - P);
    } else if (P < eii) { // columna izquierda
        C = 1;
        L = 1 + (eii - P);
    } else if (P < eid) { // renglón inferior
        L = 1;
        C = 1 + (eid - P);
    } else {
        C = level;
        L = 1 + (esd - P);
    }

    printf("Line = %d, column = %d\n", L+D, C);

    return;
}

int main()
{
    fastIO();
    if(getenv("LOCAL")){setIO();}
    
    int sz, P;
    while(scanf("%d %d", &sz, &P), sz>0) {
        solve(sz, P);
    }

    return 0;
}