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


// --------------------------------------------------------------
// Start coding here: Kruskal's Algorithm with DSU data structure
// --------------------------------------------------------------

vector<int> parent, rank_vec;

void MakeSet(int v) {
    parent[v] = v;
    rank_vec[v] = 0;
}

int FindSet(int v) {
    if (v == parent[v]) return v;
    return parent[v] = FindSet(parent[v]);
}

void UnionSets(int a, int b) {
    a = FindSet(a);
    b = FindSet(b);
    if (a != b) {
        if (rank_vec[a] < rank_vec[b]) swap(a, b);
        parent[b] = a;
        if (rank_vec[a] == rank_vec[b]) rank_vec[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n, m, cost;
vector<Edge> mst, edges; // Minimum Spanning Tree

void Init() {
    cost = 0;
    mst.clear();
    parent.clear(); parent.resize(n);
    rank_vec.clear(); rank_vec.resize(n);
}

void Kruskal() {
    Init();
    // 1. Build individual trees
    for (int u=0; u<n; u++) MakeSet(u);

    // 2. Sort edges in non-decreasing order
    sort(edges.begin(), edges.end());

    // 3. Build MST
    for (auto e : edges) {
        if (FindSet(e.u) != FindSet(e.v)) {
            cost += e.weight;
            mst.push_back(e);
            UnionSets(e.u, e.v);
        }
    }
}


int main() {
    if (getenv("LOCAL")) { setIO(); }
    printf("Krukal's Algorithm with DSU - Time Complexity: O(m log n)\n");
    cin >> n >> m;
    edges.clear();
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge e = {u,v,w};
        edges.push_back(e);
    }
    Kruskal();
    printf("Total cost: %d\n", cost);
    for (auto e : mst) {
        printf("(%d,%d) - %d\n", e.u, e.v, e.weight);
    }
    Clean();
    return 0;
}