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


// ---------------------------------------------
// Start coding here: DSU
// ---------------------------------------------

int n, m;
vector<int> parent, size_vec;

void MakeSet(int v) {
    parent[v] = v;
    size_vec[v] = 1;
}

int FindSet(int v) { // Using path compression
    if (parent[v] == v) return v;
    return parent[v] = FindSet(parent[v]);
}

void UnionSet(int a, int b) { // Union by size
    a = FindSet(a);
    b = FindSet(b);
    if (a != b) {
        if (size_vec[a] < size_vec[b]) {
            swap(a,b);
        }
        parent[b] = a;
        size_vec[a] += size_vec[b];
    }
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    printf("Disjoint Set Union\n");
    cin >> n >> m;
    parent.resize(n);
    size_vec.resize(n);
    for (int i = 0; i < m; i++) MakeSet(i);
    debug(parent); debug(size_vec);

    cout << "\nPerforming UnionSet\n\n";
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        printf("UnionSet(%d, %d)\n\t", b, a);
        UnionSet(b, a);
        debug(parent); cout << "\t"; debug(size_vec);
    }
    
    Clean();
    return 0;
}