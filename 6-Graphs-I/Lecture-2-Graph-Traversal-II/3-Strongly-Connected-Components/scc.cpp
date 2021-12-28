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
// Start coding here: Finding S.C.C.'s
// ---------------------------------------------

/*
    - adj: G, adj_rev: G^T, adj_scc: condensation graph
    - roots: root[i] will be the root of vertex i
    - root_nodes: each vertex in this list will be the root of a SCC
*/

int n, m;
vector<vector<int>> adj, adj_rev, adj_scc;
vector<bool> visited;
vector<int> order, component, roots, root_nodes;

void DFS1(int v) { // 1. Topological Sort DFS algorithm (Tarjan's approach)
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            DFS1(u);
        }
    }
    order.push_back(v);
}

void DFS2(int v) {
    visited[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v]) { // using transpoose of G: G^T
        if (!visited[u]) {
            DFS2(u);
        }
    }
}


int main() {
    if (getenv("LOCAL")) { setIO(); }
    printf("Finding Strongly Connected Components - Kosaraju's and Sharir's algorithm\n");
    cin >> n >> m;
    adj.resize(n);
    adj_rev.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);      // building G
        adj_rev[v].push_back(u);  // building G^T
    }

    // 1. Find Topological Sort
    visited.assign(n, false);
    for (int u = 0; u < n; u++) {
        if (!visited[u]) DFS1(u);
    }
    reverse(order.begin(), order.end());

    // 2. Find SCC's
    visited.assign(n, false);
    roots.assign(n, 0);
    for (auto v : order) {
        if (!visited[v]) {
            DFS2(v);
            //--------------- processing SCC
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);
            //---------------
            component.clear();
        }
    }

    // 3. Finding the condensation graph
    adj_scc.resize(n);
    for (int v = 0; v < n; v++) {
        for (auto u : adj[v]) {
            int root_u = roots[u], root_v = roots[v];
            if (root_u == root_v) {
                adj_scc[root_v].push_back(u);
            }
        }
    }


    debug(roots); // Root of SCC for every vertex
    debug(root_nodes); // Roots of SCC's
    debug(adj_scc); // Condensation graph 

    Clean();
    return 0;
}