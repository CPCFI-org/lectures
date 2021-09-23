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

int sz, P;
int line, column;

void solve() {
    //printf("%d %d\n", sz, P);
    int P_right_upper_corner = ceil(sqrt(P));
    if (P_right_upper_corner % 2 == 0) P_right_upper_corner += 1;
    int level = P_right_upper_corner;

    int col_center = ceil((float)sz/2), row_center = col_center;
    int col_level = col_center + (level-1)/2, row_level = col_level;

    //printf("Level value: %d\nCenterC (%d,%d)\nLevelC (%d,%d)\n", level, col_center, row_center, col_level, row_level);

    int k = level - 1;
    // upper right corner
    ll urc = level*level;
    ll lrc = urc - k;
    ll llc = lrc - k;
    ll ulc = llc - k;

    //printf("Corners:\n%lld %lld\n%lld %lld\n", ulc, urc, llc, lrc);

    // First base case
    if (sz == 1 || P == 1) { line = row_center; column = col_center; return; }

    if (ulc > P) {
        line = row_level;
        column = (col_level - k) + (ulc - P);
    } else if (llc > P) {
        line = (row_level-k) + (llc - P);
        column = col_level - k;
    } else if (lrc > P) {
        line = row_level - k;
        column = col_level - (lrc - P);
    } else if (urc > P) {
        line = row_level - (urc - P);
        column = col_level;
    } else {
        line = row_level;
        column = col_level;
    }

    return;
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    while (scanf("%d %d", &sz, &P), sz != 0 && P != 0) {
        solve();
        printf("Line = %lld, column = %lld.\n", line, column);
    }
    return 0;
}