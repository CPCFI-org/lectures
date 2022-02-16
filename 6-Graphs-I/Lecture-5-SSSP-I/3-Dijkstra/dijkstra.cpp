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
    + Lecture name: Dijkstra's O(m log n) algorithm
    + CPCFI
    + UNAM's School of Engineering
*/

const long long INF = 1e18;

void Dijkstra(int source, vector<long long> &D, vector<int> &P, 
    const vector<vector<pair<int, int>>> adj) {
    
    int n = adj.size();
    D.assign(n, INF);
    P.assign(n, -1);
    set<pair<int,int>> Q; // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>) Q;

    D[source] = 0;
    Q.insert({0, source}); // {distance, node} // Q.push({0, source});
    while (!Q.empty()) {
        auto v = Q.begin()->second; // Q.top().second;
        // int d_v = Q.top().first;
        Q.erase(Q.begin()); // Q.pop();

        /*
        if (D[v] != d_v) continue; // this prevents from using a previously seen edge
        */

        for (auto e : adj[v]) {
            auto to = e.first;
            auto weight = e.second;

            if (D[v] + weight < D[to]) {
                Q.erase({D[to], to});
                D[to] = D[v] + weight;
                P[to] = v;
                Q.insert({D[to], to}); // Q.push({D[to], to});
            }
        }
    }
}

vector<int> SSSP(int source, int target, const vector<int> &P, 
    const vector<long long> &D) {
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
    vector<vector<pair<int,int>>> adj(n);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source = 2;
    int target = 4;

    vector<long long> D; // D: distance
    vector<int> P; // P: predecessor
    Dijkstra(source, D, P, adj);

    auto path = SSSP(source, target, P, D);
    cout << "Path length: " << path.size() << endl;
    cout << "Path: ";
    for (auto p : path) cout << p << " ";
    cout << endl;

    return 0;
}