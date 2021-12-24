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
// Start coding here: Checking for acyclcicity
// ---------------------------------------------


// Directed graph only
int n, m;
vector<vector<int>> adj;
vector<int> color, parent;
int cycle_start, cycle_end;

bool DFS(int v) { // modified DFS that checks if a cycle exists
    color[v] = 1; // Visited
    for (auto u : adj[v]) {
        if (color[u] == 0) { // Not visited
            parent[u] = v;
            if (DFS(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2; // Exited
    return false;
}

void FindCycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++)
        if (color[v] == 0 && DFS(v))
            break;

    if (cycle_start == -1) {
        printf("Acyclic\n");
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_end);
        auto curr_node = parent[cycle_end];
        while (curr_node != cycle_start) {
            cycle.push_back(curr_node);
            curr_node = parent[curr_node];
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        printf("Cycle found: ");
        for (auto u : cycle) cout << u << " ";
        cout << endl;
    }
}

// Undirected graph
vector<bool> visited;
bool DFS_ug(int v, int par) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (u == par) continue;
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (DFS_ug(u, parent[u]))
            return true;
    }
    return false;
}

void FindCycle_ug() {
    visited.assign(n, false);
    parent.assign(n, false);
    cycle_start = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && DFS_ug(v, parent[v])) break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_end);
        auto curr_node = parent[cycle_end];
        while (curr_node != cycle_start) {
            cycle.push_back(curr_node);
            curr_node = parent[curr_node];
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        printf("Cycle found: ");
        for (auto u : cycle) cout << u << " ";
        cout << endl;
    }
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    
    printf("Checking for acyclicity in a Directed Graph\n");
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    FindCycle();
    Clean();
    
    printf("Checking for acyclicity in an Undirected Graph\n");
    cin >> n >> m;
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FindCycle_ug();
    Clean();
    return 0;
}