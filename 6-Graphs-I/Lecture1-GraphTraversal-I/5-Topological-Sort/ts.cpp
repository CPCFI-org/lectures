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
// Start coding here: Topological Sort
// ---------------------------------------------

class DirectedGraph {
    int m_num_of_nodes;
    vector<vector<int>> m_adj;
    vector<int> m_color, m_topo_sort;
    int m_back_edges = 0;

    public:
        DirectedGraph(int num_of_nodes) {
            m_num_of_nodes = num_of_nodes;
            m_adj.resize(num_of_nodes);
            m_color.resize(num_of_nodes);
            m_topo_sort.resize(num_of_nodes);
        }

        void add(int u, int v) {
            m_adj[u].push_back(v);
        }

        bool IsAcyclic() {
            m_back_edges = 0; m_topo_sort.clear();
            for (int u = 0; u < m_num_of_nodes; u++) {
                if (m_color[u] == 0) {
                    DFS(u);
                }
            }
            return m_back_edges > 0 ? false : true;
        }

        vector<int> FindTopoSort() {
            if (!IsAcyclic()) return {};
            
            m_color.assign(m_num_of_nodes, 0);
            m_topo_sort.clear();

            for (int u = 0; u < m_num_of_nodes; u++) {
                if (m_color[u] == 0) {
                    DFS(u);
                }
            }
            reverse(m_topo_sort.begin(), m_topo_sort.end());
            return m_topo_sort;
        }
    
    private: 
        void DFS(int u) {
            m_color[u] = 1;
            for (auto v : m_adj[u]) {
                if (m_color[v] == 0) {
                    DFS(v);
                } else if (m_color[v] == 1) {
                    m_back_edges++;
                }
            }
            m_color[u] = 2;
            m_topo_sort.push_back(u);
        }
};

int main() {
    if (getenv("LOCAL")) { setIO(); }

    // First, let's see how to check if a directed graph contains any cycles
    cout << "Checking for cycles in a directed graph" << endl;
    int n1, m1; cin >> n1 >> m1;
    DirectedGraph dg1 {n1};
    for(int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        dg1.add(u, v);
    }
    cout << "Is DG1 acyclic?: " << (dg1.IsAcyclic() ? "True" : "False") << endl;
    Clean();

    cout << "Finding a topological sort" << endl;
    int n2, m2; cin >> n2 >> m2;
    DirectedGraph dg2 {n2};
    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        dg2.add(u,v);
    }
    cout << "Is DG2 acyclic?: " << (dg2.IsAcyclic() ? "True" : "False") << endl;
    vector<int> topo_sort = dg2.FindTopoSort();
    debug(topo_sort);
    Clean();
    // Now, let's find a Topological Sort in a DAG
    return 0;
}