#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl                        '\n'
#define fastIO()                    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& (v) : (arr))
#define debug(x)                    cout << #x << " = "; _debug(x); cout << endl;
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

    FILE *exist_in_file;
    exist_in_file = freopen(in_file.c_str(), "r", stdin);
    if(!exist_in_file){
        exist_in_file = freopen(in_file.c_str(), "w", stdout);
        fclose(exist_in_file);
    }

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

template <typename type>
struct Hungarian{
	int N;
	ll inf=LLONG_MAX;
	vector<vector<type>> cost;
	int n, max_match;
	vector<type> lx, ly, xy, yx, slack, slackx, prev;
	vector<bool> S, T;
	Hungarian(int N) : N(N), cost(N, vector<type>(N)), lx(N, 0), ly(N, 0), xy(N), yx(N), slack(N), slackx(N),
		prev(N), S(N), T(N) {}

	void initLabels() {
		n=N;
		for(int x=0; x < n; x++)
			for(int y=0; y < n; y++)
				lx[x]=max(lx[x], cost[x][y]);
	}

	void augment() {
		if(max_match == n) return;
		int x, y, root;
		vector<ll> q(N);
		int wr=0, rd=0;
		for(int i=0; i<N; i++) {
			S[i]=false, T[i]=false, prev[i]=-1;
		}
		for(x=0; x < n; x++) {
			if(xy[x] == -1) {
				q[wr++]=x;
				root=x;
				prev[x]=-2;
				S[x]=true;
				break;
			}
		}
		for(y=0; y < n; y++) {
			slack[y]=lx[root] + ly[y] - cost[root][y];
			slackx[y]=root;
		}
		while(true) {
			while(rd < wr) {
				x=q[rd++];
				for(y=0; y < n; y++)
					if(cost[x][y] == lx[x] + ly[y] && !T[y]){
						if(yx[y] == -1) break;
						T[y]=true;
						q[wr++]=yx[y];
						addToTree(yx[y], x);
					}
				if(y < n) break;
			}
			if(y < n) break;
			updateLabels();
			wr=rd=0;
			for(y=0; y < n; y++)
				if(!T[y] && slack[y] == 0){
					if(yx[y] == -1) 	{
						x=slackx[y];
						break;
					} else{
						T[y]=true;
						if(!S[yx[y]]){
							q[wr++]=yx[y];
							addToTree(yx[y], slackx[y]);
						}
					}
				}
			if(y < n) break;
		}
		if(y < n) {
			max_match++;
			for(int cx=x, cy=y, ty; cx != -2; cx=prev[cx], cy=ty)	{
				ty=xy[cx];
				yx[cy]=cx;
				xy[cx]=cy;
			}
			augment();
		}
	}

	void updateLabels() {
		ll x, y; type delta=inf;
		for(y=0; y < n; y++) {
			if(!T[y])
				delta=min(delta, slack[y]);
		}
		for(x=0; x < n; x++) {
			if(S[x]) lx[x]-=delta;
		}
		for(y=0; y < n; y++){
			if(T[y]) ly[y]+=delta;
		}
		for(y=0; y < n; y++) {
			if(!T[y])
				slack[y]-=delta;
		}
	}

	void addToTree(int x, int prevx){
		S[x]=true;
		prev[x]=prevx;
		for(int y=0; y < n; y++) {
			if(lx[x] + ly[y] - cost[x][y] < slack[y]) {
				slack[y]=lx[x] + ly[y] - cost[x][y];
				slackx[y]=x;
			}
		}
	}

	ll hungarian() {
		ll ret=0;
		max_match=0;
		for(int i=0; i<N; i++) {
			xy[i]=-1, yx[i]=-1;
		}
		initLabels();
		augment();
		for(int x=0; x < n; x++) {
			ret+=cost[x][xy[x]];
		}
        vi ans(n, 0);
        FO(x, n){
            ans[xy[x]] = x+1;
        }
        print(ans);
		return ret;
	}
};

void solve(){
    int n; cin >> n;
    vi nums(n);
    FO(i, n) cin >> nums[i];
    debug(nums);
    return;
}

int main()
{
    fastIO();
    if(getenv("LOCAL")){setIO();}
    int T=1;
    FO(tc, T){
        // cout << "Case #" << tc+1 << ":";
        solve();
    }	
    return 0;
}