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
// Start coding here: Articulation Points and Bridges
// --------------------------------------------------

int n, m, dfs_timer;
vector<vector<int>> adj;
vector<bool> visited, is_ap;
vector<int> entry, low;
vector<pair<int,int>> bridges;

// Modified DFS version to return number of children considering node u
// as the root of the DFS spanning tree
int DFS(int u, int p=-1) {
    int children = 0;
    visited[u] = true;
    entry[u] = low[u] = dfs_timer++;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            /*
                Check if node v's time of entry is smaller than current node u's
                least time of entry node

                - low[u] is an adjacent node to u with the least time of entry 
            */
            low[u] = min(low[u], entry[v]);
        } else {
            children++;
            DFS(v, u);
            //-----------------------
            // Finding Bridges
            if (entry[u] < low[v]) {
                bridges.push_back(make_pair(u, v));
            }
            //-----------------------
            /*
                Node u will be an AP if its time of entry is less than the time
                of an adjacent node of u that has the smallest time of entry
            */
           if (entry[u] <= low[v]) {
               is_ap[u] = true;
           }
           low[u] = min(low[u], low[v]);
        }
    }
    return children;
}

void FindArticulationPointsAndBridges() {
    visited.assign(n, false);
    is_ap.assign(n, false);
    entry.assign(n, -1);
    low.assign(n, -1);
    dfs_timer = 0;
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            int curr_children = DFS(u, u);
            is_ap[u] = (curr_children > 1) ? true : false;
            debug(curr_children);
        }
    }
    cout << "\nArticulation Points:" << endl;
    for (int u = 0; u < n; u++) {
        if (is_ap[u]) {
            printf("Node %d\n", u);
        }
    }
    cout << "\nBridges:" << endl;
    for (auto p : bridges) {
        printf("Edge (%d,%d)\n", p.first, p.second);
    }
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    printf("Finding Articulation Points and Bridges\n");
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FindArticulationPointsAndBridges();
    Clean();
    return 0;
}