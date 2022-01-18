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

/*
    + Lecture name: Second Best Minimum Spanning Tree
    + CPCFI
    + UNAM School of Engineering
*/

int n, m;
vector<int> parent, rank_vec;
vector<vector<int>> adj;

const int INF = 1e9;

void make_set(int v) {
    parent[v] = v;
    rank_vec[v] = 0;
}

int find_set(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_vec[a] < rank_vec[b]) swap(a, b);
        parent[b] = a;
        if (rank_vec[a] == rank_vec[b]) rank_vec[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator < (const Edge & other) {
        return weight < other.weight;
    }
    bool operator == (const Edge & other) {
        if (u == other.u && v == other.v && weight == other.weight) {
            return true;
        }
        return false;
    }
};

vector<Edge> Kruskal(vector<Edge> edges, int& cost) {
    parent.clear(); rank_vec.clear();
    for (int i = 0; i < n; i++) {
        make_set(i);
    }
    vector<Edge> mst;
    cost = 0;
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            mst.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    return mst;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) { setIO(); }
    cin >> n >> m;
    parent.resize(n);
    rank_vec.resize(n);
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u,v,weight});
    }

    // 1. Find MST using Kruskal's algorithm
    int mst_cost = 0;
    auto mst = Kruskal(edges, mst_cost);

    cout << "MST cost = " << mst_cost << endl;
    for (auto e : mst) {
        cout << "(" << e.u << "," << e.v << ") - " << e.weight << endl;
    }
    cout << endl;
    
    // 2. Find Second Best MST with lowest weight
    int second_mst_cost = INF;
    vector<Edge> second_mst;
    for (auto e : mst) {
        vector<Edge> temp;
        for (auto curr : edges) {
            if (curr == e) {
                continue;
            } else {
                temp.push_back(curr);
            }
        }
        int temp_cost = 0;
        auto temp_mst = Kruskal(temp, temp_cost);
        if (temp_cost < second_mst_cost) {
            second_mst_cost = temp_cost;
            second_mst = temp_mst;
        }
    }

    cout << "Second MST cost=" << second_mst_cost << endl;
    for (auto e : second_mst) {
        printf("(%d,%d) - %d\n", e.u, e.v, e.weight);
    }

    return 0;
}