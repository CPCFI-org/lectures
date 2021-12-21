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
// Start coding here: Connected Components
// ---------------------------------------------

#define MAXN 15
using n_type = int;
vector<vector<n_type>> adj(MAXN); // zero-based
vector<bool> visited(MAXN);
vector<vector<n_type>> cc; // connected components

void dfs(n_type u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(v);
        }
    }
}

void find_cc(int num_of_nodes) {
    for(int i = 0; i < num_of_nodes; i++) {
        visited[i] = false;
    }
    vector<n_type> component;
    for (int i = 0; i < num_of_nodes; i++) {
        if (!visited[i]) {
            if (component.size() > 0) cc.push_back(component);
            component.clear();
            dfs(i);
        }
        component.push_back(i);
    }
    cc.push_back(component);
}


int main() {
    if (getenv("LOCAL")) { setIO(); }

    // number of nodes
    int num_of_nodes, num_of_roads;
    cin >> num_of_nodes >> num_of_roads;

    // Graph
    for(int i = 0; i < num_of_roads; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    debug(adj);

    // Connected components
    find_cc(num_of_nodes);
    debug(cc);

    return 0;
}