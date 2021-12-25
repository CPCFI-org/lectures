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
// Start coding here: BFS
// ---------------------------------------------

class UndirectedGraph {
    using number_type = int;

    number_type m_number_of_nodes {};
    vector<vector<number_type>> m_adjacency_list;
    vector<bool> m_visited {};
    vector<number_type> m_parent {};
    vector<number_type> m_distance {};
    queue<number_type>  m_queue {};

    private:
        void Restart(vector<number_type>& v) {
            v.clear();
            v.resize(m_number_of_nodes);
        }
        void Restart(vector<bool>& v) {
            v.clear();
            v.resize(m_number_of_nodes);
        }
        void RestartVectors() {
            Restart(m_visited);
            Restart(m_parent);
            Restart(m_distance);
            m_queue = {};
        }

    public:
        UndirectedGraph(number_type number_of_nodes) {
            m_number_of_nodes = number_of_nodes;
            m_adjacency_list.resize(m_number_of_nodes);
            m_visited.resize(m_number_of_nodes);
            m_parent.resize(m_number_of_nodes);
            m_distance.resize(m_number_of_nodes);
        }

        void add(number_type source, number_type target) {
            m_adjacency_list[source].push_back(target);
        }

        void BFS(number_type source_vertex, bool verbose) {
            m_queue.push(source_vertex);
            m_visited[source_vertex] = true;
            m_distance[source_vertex] = 0;
            m_parent[source_vertex] = -1; 

            if (verbose) cout << source_vertex << " ";
            while (!m_queue.empty()) {
                number_type curr_vertex = m_queue.front();
                m_queue.pop();
                for (auto neighbor : m_adjacency_list[curr_vertex]) {
                    if (m_visited[neighbor]) {

                    } else {
                        if (verbose) cout << neighbor << " ";
                        m_queue.push(neighbor);
                        m_visited[neighbor] = true;
                        m_parent[neighbor] = curr_vertex;
                        m_distance[neighbor] = m_distance[curr_vertex] + 1;
                    }
                }
            }
            if (verbose) cout << endl;
        }

        vector<number_type> ShortestPathFromSource(number_type source, number_type u, bool verbose) {
            RestartVectors();
            BFS(source, false);

            if (!m_visited[u]) return {};

            vector<number_type> path;
            for (number_type v = u; v != -1; v = m_parent[v]) {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            return path;

            return {};
        }

};

int main() {
    if (getenv("LOCAL")) { setIO(); }

    vector<vector<int>> adj = {
        {1,4}, {0,5,2}, {1,3}, {2,7}, {0,8}, {1,6,10}, {5,11}, {3,12}, {4,9},
        {8,10}, {5,9,11}, {6,10,12}, {7,11}
    };

    int number_of_nodes = adj.size();
    UndirectedGraph ug {number_of_nodes};
    for (int u = 0; u < number_of_nodes; u++) {
        for (int v : adj[u]) {
            ug.add(u, v);
        }
    }

    cout << "BFS path" << endl;
    ug.BFS(5, true);
    Clean();

    int s = 5;
    int u = 12;
    cout << "Finding Shortest Path from source: " << s << " to vertex u: " << u << endl;
    auto path = ug.ShortestPathFromSource(s, u, true);
    for (auto v : path) {
        cout << v << " ";
    }
    cout << endl;
    Clean();
     
    return 0;
}