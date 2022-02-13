#include <bits/stdc++.h>
using namespace std;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r",  stdin);
    freopen(out_file.c_str(), "w",  stdout);
}

/*
    + Lecture name: Dijkstra's Algorithm
    + CPCFI
    + UNAM's School of Engineering
*/

const int INF = 10000000;

void Dijkstra(int s, vector<int> &D, vector<int> &P, 
    const vector<vector<pair<int,int>>> &adj) {
    
    int n = adj.size();
    D.assign(n, INF);
    P.assign(n, -1);
    vector<bool> U(n, false);

    D[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1; // v will be the next unmarked vertex with lowest distance 
        for (int j = 0; j < n; j++) {
            if (!U[j] && (v == -1 || D[j] < D[v])) {
                v = j;
            }
        }

        if (D[v] == INF) break;

        U[v] = true;
        for (auto e : adj[v]) {
            int to = e.first;
            int weight = e.second;

            if (D[v] + weight < D[to]) {
                D[to] = D[v] + weight;
                P[to] = v;
            }
        }
    }
}

vector<int> SSSP(int source, int target, const vector<int> &P, 
    const vector<int> &D) {
    if (D[target] == INF) return {};

    vector<int> path;
    path.push_back(target);
    auto p = P[target];
    while (p != source) {
        path.push_back(p);
        p = P[p];
    }   
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();

    int n, m, u, v, w;
    vector<vector<pair<int,int>>> adj;

    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source = 2;
    int target = 4;

    vector<int> D, P;
    Dijkstra(source, D, P, adj);

    auto path = SSSP(source, target, P, D);
    cout << "Path length: " << path.size() << endl;
    cout << "Path: ";
    for (auto p : path) cout << p << " ";
    cout << endl;

    return 0;
}