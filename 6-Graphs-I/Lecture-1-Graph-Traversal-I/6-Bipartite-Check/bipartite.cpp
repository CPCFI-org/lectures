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
// Start coding here: Bipartite Graph Check
// ---------------------------------------------

int n, m; 
vector<vector<int>> adj;
vector<int> side; // 0 or 1
bool is_bipartite = true;

void BipartiteCheck() {
    queue<int> q;
    for (int st = 0; st < n; st++) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                auto v = q.front(); q.pop();
                for (auto u : adj[v]) {
                    if (side[u] == -1) { // Not visited
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        if (side[u] == side[v]) {
                            is_bipartite = false;
                            return;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    printf("Bipartite Graph Check\n");
    cin >> n >> m;
    adj.resize(n);
    side.assign(n, -1);
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BipartiteCheck();
    cout << (is_bipartite ? "YES" : "NO") << endl;
    Clean();
    return 0;
}