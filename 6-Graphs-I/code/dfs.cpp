#include <bits/stdc++.h>
using namespace std;

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

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void setIO(){
	string file = __FILE__;
	file = string(file.begin(), file.end()-3);
	string in_file = file+"in";
	string out_file = file+"out";
	freopen(in_file.c_str(), "r", stdin);
	freopen(out_file.c_str(), "w", stdout);
}

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

void solve() {
    int V;
    si(V);
    cout << V << endl;
}

int main() {
    //cin.tie(0); cout.tie(0);
    cin.tie(NULL);
    string name;
    std::cout << "Enter name:";
    std::cin >> name;
    // setIO();
    // int T=1;
    // FO(tc, T){
    //     solve();
    // }
    return 0;
}