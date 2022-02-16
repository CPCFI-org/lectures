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
    + Lecture name: Bellman-Ford algorithm (considering negative cycles)
    + CPCFI
    + UNAM's School of Engineering
*/

struct edge {
    int u, v;
    double weight;
};

const double INF=1e18;

void BellmanFord(int s, int n, int m, vector<double> & dist, vector<int> & pred, 
    vector<int> &cycle, const vector<edge> &edges) {
        
    dist.assign(n, INF);
    pred.assign(n, -1);
    int node_x;

    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        node_x = -1; // last node where a relaxation is performed
        for (int j = 0; j < m; j++) {
            auto edge = edges[j];
            auto u = edge.u, v = edge.v;
            auto weight = edge.weight;
            
            if (dist[v] < INF) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = max(-INF, dist[u] + weight);
                    pred[v] = u;
                    node_x = v;
                }
            }
        }
    }
    
    if (node_x == -1) {
        // No negative cycle
        cycle = {};
    } else {
        int w = node_x;
        for (int i = 0; i < n; i++)
            w = pred[w];
        
        cycle.push_back(w);
        auto par = pred[w];
        while (par != w) {
            cycle.push_back(par);
            par = pred[par];
        }
        cycle.push_back(w);
        reverse(cycle.begin(), cycle.end());
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();

    // 0: Read Graph
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v; double w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // 1: Bellman-Ford algorithm
    int source = 2;
    vector<double> distance;
    vector<int> predecessor;
    vector<int> cycle;
    BellmanFord(source, n, m, distance, predecessor, cycle, edges);

    if (cycle.empty()) {
        cout << "No negative cycle found" << endl;
    } else {
        cout << "Negative cycle: ";
        for (auto p : cycle) cout << p << ' ';
        cout << endl;
    }
    
    return 0;
}
