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
// Start coding here: Kruskal's Algorithm
// ---------------------------------------------

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n, m, cost; 
vector<Edge> edges, mst; // mst: Minimum Spanning Tree
vector<int> tree_id;

void Init() {
    cost = 0;
    tree_id.clear(); tree_id.resize(n);
    mst.clear();
}

void Kruskal() {
    Init();
    // 1. All the nodes isolated. Each node is its parent
    for (int i=0; i < n; i++) tree_id[i] = i;

    // 2. Sort edges by weight in non-decreasing order
    sort(edges.begin(), edges.end());

    // 3. Build MST
    for (Edge e : edges) { // Pick all nodes from first to last

        // If the nodes of the current edge e belong to different trees,
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            mst.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) 
                if (tree_id[i] == old_id) tree_id[i] = new_id; // combine them together
        }
    }
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    printf("Kruskal's Algorithm in O(m log m + n^2)\n");
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge e = {u, v, w};
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