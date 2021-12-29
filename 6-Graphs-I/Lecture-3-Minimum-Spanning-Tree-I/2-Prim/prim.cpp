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


// ---------------------------------------------------
// Start coding here: Prim's Algorithm for finding MST
// ---------------------------------------------------
const int INF=1000000000;

struct Edge {
    int w = INF, to = -1;
};

int n, m;
vector<vector<int>> adj; // Adjacency Matrix

void Prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w)) {
                v = j;
            }
        }
        if (min_e[v].w == INF) {
            cout << "No MST" << endl;
            exit(0);
        }
        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1) {
            printf("(%d,%d): %d\n", v, min_e[v].to, min_e[v].w);
        }
        for (int to = 0; to < n; to++) {
            if (adj[v][to] < min_e[to].w) {
                min_e[to] = {adj[v][to], v};
            }
        }
    }
    printf("Total weight: %d\n", total_weight);
}


// Prim on Sparse Graphs O(m log n)
struct Edge_Sparse {
    int w = INF, to  = -1;
    bool operator<(Edge_Sparse const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

vector<vector<Edge_Sparse>> adj_sparse; // Adjacency List

void Prim_Sparse() {
    int total_weight = 0;
    vector<Edge_Sparse> min_e(n);
    min_e[0].w = 0;
    set<Edge_Sparse> q;
    q.insert({0,0});
    vector<bool> selected(n, false);
    for (int i=0; i < n; i++) {
        if (q.empty()) {
            cout << "NO MST" << endl;
            exit(0);
        }

        int v = q.begin()->to;

        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[v].to != -1) {
            printf("(%d,%d): %d\n", v, min_e[v].to, min_e[v].w);
        }

        for (auto e : adj_sparse[v]) {
            if (!selected[e.to] && e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }

    }
    printf("Total weight: %d\n", total_weight);
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    printf("Prim's Algorithm - Dense O(n^2)\n");
    cin >> n >> m;
    adj.resize(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    Prim();
    Clean();
    printf("Prim's Algorithm - Sparse O(m log n)\n");
    cin >> n >> m;
    adj_sparse.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_sparse[u].push_back({w, v});
        adj_sparse[v].push_back({w, u});
    }
    Prim_Sparse();
    Clean();
    return 0;
}