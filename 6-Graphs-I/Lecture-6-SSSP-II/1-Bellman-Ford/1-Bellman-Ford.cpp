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

void Clean() {
    printf("\n==================\n\n");
}

/*
    + Lecture name: Bellman-Ford algorithm
    + CPCFI
    + UNAM's School of Engineering
*/

const double INF=1e18;

struct edge {
    int u, v, weight;
};

void BellmanFord(int s, int n, int m, vector<double> &d, vector<int> & p, 
    const vector<edge> &edges) {
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    for (int i = 0; i < n-1; i++) {
        bool any = false;
        for (int j = 0; j < m; j++) {
            auto edge = edges[j];
            if (d[edge.u] < INF) {
                if (d[edge.u] + edge.weight < d[edge.v]) {
                    d[edge.v] = d[edge.u] + edge.weight;
                    p[edge.v] = edge.u;
                    any = false;
                }
            }
        }
        if (!any) break;
    }
}

vector<int> SSSP(int s, int t, const vector<double> &d, const vector<int> &p) {
    if (d[t] == INF) return {};
    vector<int> path;
    path.push_back(t);
    auto par = p[t];
    while (par != s) {
        path.push_back(par);
        par = p[par];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) { setIO(); }

    int n, m, u, v, w;
    cin >> n >> m;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Bellman Ford
    int source = 0;
    vector<double> d;
    vector<int> p;
    BellmanFord(source, n, m, d, p, edges);

    for (auto di : d) cout << di << ' ';
    cout << endl;

    // Retrieve the path 
    int target = 2;
    auto path = SSSP(source, target, d, p);
    for (auto p : path) cout << p << ' ';
    cout << endl;
    return 0;
}