#include <bits/stdc++.h>
using namespace std;

#define debug(x)                    cout << #x << " = "; _debug(x); cout << endl;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r",  stdin);
    freopen(out_file.c_str(), "w",  stdout);
}

void Clean() {
    printf("\n==================\n\n");
}

template <typename T>
void _debug(T& x){
    cout << x;
}

template <typename T>
void _debug(vector<T>& vec){
    int n = vec.size();
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    for (int i = 0; i < n-1; i++) {
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n-1]); cout << "]";
}


// --------------------------------------------------
// Start coding here: Segment Tree for sum queries
// Reference: https://codeforces.com/blog/entry/18051
// --------------------------------------------------

#define INF 1e5
const int N = 1e5;
int n;
int t[2 * N];

void build() {
    for (int i = n - 1; i > 0; --i)  
        t[i] = t[i<<1] + t[i<<1 | 1];
}

void modify(int p, int value) {  // set value at position p
    for (t[p+=n] = value; p > 1; p >>= 1) 
        t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++]; // least significant bit of l is 1? => l is odd?
        if (r&1) res += t[--r]; // least significant bit of r is 1? => r is odd?
    }
    return res;
}

int main() {
    if (getenv("LOCAL")) setIO();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
    build();
    printf("%d\n", query(3, 8+1)); // [l,r)
    return 0;
}