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
// Start coding here: 
// ---------------------------------------------

class UndirectedGraph {
    using n_type = int;
    vector<vector<n_type>> m_adj;
    n_type m_number_of_nodes, m_dfs_timer;
    vector<n_type> m_color; // 0: unvisited, 1: visited, 2: exited from the vertex
    vector<n_type> m_time_in, m_time_out;

    public:
        UndirectedGraph(n_type number_of_nodes) {
            m_number_of_nodes = number_of_nodes;
            m_dfs_timer = 0;
            m_adj.resize(m_number_of_nodes);
            m_color.resize(m_number_of_nodes);
            m_time_in.resize(m_number_of_nodes);
            m_time_out.resize(m_number_of_nodes);
        }

        void add(n_type u, n_type v) {
            m_adj[u].push_back(v);
        }

        void DFS(n_type v, bool verbose) {
            if (verbose) cout << v << " ";
            m_time_in[v] = m_dfs_timer++;
            m_color[v] = 1;
            for (n_type u : m_adj[v]) {
                if (m_color[u] == 0) {
                    DFS(u, verbose);
                }
            }
            m_color[v] = 2;
            m_time_out[v] = m_dfs_timer++;
        }

        vector<n_type> GetColor() { return m_color; }
        vector<n_type> GetTimeIn() { return m_time_in; }
        vector<n_type> GetTimeOut() { return m_time_out; }
};

int main() {
    if (getenv("LOCAL")) { setIO(); }
    
    vector<vector<int>> adj1 = {
        {1}, {0,2,3}, {1,3}, {1,2,4}, {3,5}, {4},
        {6}, {7,8}, {6}
    };
    int n = adj1.size();
    UndirectedGraph ug { n };
    for (int u=0; u < n; u++) {
        for (auto v : adj1[u]) {
            ug.add(u, v);
        }
    }
    ug.DFS(0, true);
    auto color = ug.GetColor();
    auto time_in = ug.GetTimeIn();
    auto time_out = ug.GetTimeOut();
    debug(color);
    debug(time_in);
    debug(time_out);
    Clean();

    vector<vector<int>> adj2 = {
        {1,3,6}, {2}, {6,3}, {4,5}, {}, {0}, {}
    };
    int n2 = adj2.size();
    UndirectedGraph ug2 { n2 };
    for (int u=0; u < n2; u++) {
        for (auto v : adj2[u]) {
            ug2.add(u, v);
        }
    }
    ug2.DFS(0, true);
    color = ug2.GetColor();
    time_in = ug2.GetTimeIn();
    time_out = ug2.GetTimeOut();
    debug(color);
    debug(time_in);
    debug(time_out);
    Clean();

    
    return 0;
}