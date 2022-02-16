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
    + Lecture name: Single Source Shortest Paths on Unweighted graphs
    + CPCFI
    + UNAM's School of Engineering
*/

void BFS(int u, int n, vector<int> &parent, vector<int> &distance, 
    const vector<vector<int>> &adj) {
    
    distance.assign(n, -1);
    parent.resize(n);
    queue<int> q;

    distance[u] = 0;
    parent[u] = -1;
    q.push(u);

    while (!q.empty()) {
        auto w = q.front();
        q.pop();
        for (auto v : adj[w]) {
            if (distance[v] == -1) {
                distance[v] = distance[w] + 1;
                parent[v] = w;
                q.push(v);
            }
        }
    }
}

vector<int> FindPath(int source, int target, const vector <int> &parent) {
    if (parent[target] == -1 || source == target) {
        return {};
    }

    vector<int> path;
    path.push_back(target);

    int p = parent[target];
    while (p != source) {
        path.push_back(p);
        p = parent[p];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());

    return path;
}


int main() {
    if (getenv("LOCAL")) setIO();
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source = 5, target = 12;
    vector<int> distance, parent;
    BFS(source, n, parent, distance, adj);

    auto path = FindPath(source, target, parent);
    cout << "Path length: " << path.size() << endl;
    cout << "Path: ";
    for (auto p : path)
        cout << p << ' ';
    cout << endl;

    return 0;
}