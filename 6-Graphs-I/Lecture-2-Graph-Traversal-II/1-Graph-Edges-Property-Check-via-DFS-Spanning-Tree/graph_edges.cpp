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
// Start coding here: Graph Edges Property Check
// ---------------------------------------------

int n, m, cc=0;
vector<vector<int>> adj;
vector<int> color, parent;

void GraphCheck(int u) {
    color[u] = 1;
    for (auto v : adj[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            GraphCheck(v);
        } else if (color[v] == 1) {
            if (v == parent[u]) {
                printf("\tTwo ways (%d,%d) - (%d,%d)\n", u, v, v, u);
            } else {
                printf("\tBack edge (%d,%d) (Cycle)\n", u, v);
            }
        } else if (color[v] == 2) {
            printf("\tForward edge (%d,%d)\n", u, v);
        }
    }
    color[u] = 2;
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    cin >> n >> m;
    adj.resize(n);
    color.assign(n, 0);
    parent.assign(n, 0);
    for (int i=0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("Graph Edge Property Check (unvisited, visited, exited)\n");
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            printf("Component %d\n", ++cc);
            GraphCheck(i);
        }
    }
    return 0;
}