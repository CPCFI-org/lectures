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
// Start coding here: Finding Bridges in O(m+n)
// ---------------------------------------------

int n, m, dfs_timer;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> entry, low;

void DFS(int u, int p = -1) {
    visited[u] = true;
    entry[u] = low[u] = dfs_timer++;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], entry[v]);
        } else {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > entry[u]) { // Found a bridge
                printf("\tEdge (%d,%d) is a bridge\n", u, v);
            }
        }
    }
}

void FindBridges() {
    dfs_timer = 0;
    visited.assign(n, false);
    entry.assign(n, -1);
    low.assign(n, -1);
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            DFS(u);
        }
    }
}

int main() {
    if (getenv("LOCAL")) { setIO(); }

    printf("Finding Bridges in O(n+m) - Multiple bridges\n");
    cin >> n >> m;
    adj.resize(n);
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FindBridges();
    Clean();

    printf("Finding Bridges in O(n+m) - No bridges\n");
    cin >> n >> m;
    adj.resize(n);
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FindBridges();
    Clean();
    return 0;
}