#include <bits/stdc++.h>
using namespace std;

#define debug(x)                    cout << #x << " = "; _debug(x); cout << endl;

void setIO() {
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
void _debug(T& x) {
    cout << x;
}

template <typename T>
void _debug(vector<T>& vec) {
    int n = vec.size();
    if(n == 0){cout << "[ ]"; return;}
    cout << "[";
    for (int i = 0; i < n-1; i++) {
        _debug(vec[i]); cout << " ";
    }
    _debug(vec[n-1]); cout << "]";
}


// ---------------------------------------------
// Start coding here: Prufer code
// ---------------------------------------------

int n, m;
vector<vector<int>> adj;
vector<int> parent;

void DFS(int u) {
	for (auto v : adj[u]) {
		if (u != parent[v]) {
			parent[v] = u;
			DFS(v);
		}
	}
}

vector<int> PruferCode(const vector<vector<int>> & adj) {
	// 1. Find the parent of each node
	parent.resize(n);
	parent[n-1] = -1;
	DFS(n-1); // should we check for connected components?

	// 2. Find the first smallest leaf
	int ptr = -1;
	vector<int> degree(n);
	for (int i = 0; i < n; i++) {
		degree[i] = adj[i].size();
		if (degree[i] == 1 && ptr == -1) {
			ptr = i;
		}
	}

	// 3. Build Prufer Code
	vector<int> code(n - 2);
    int leaf = ptr;
    for (int i = 0; i < n - 2; i++) {
        int next = parent[leaf];
        code[i] = next;
        if (--degree[next] == 1 && next < ptr) {
            leaf = next;
        } else {
            ptr++;
            while (degree[ptr] != 1)
                ptr++;
            leaf = ptr;
        }
    }

    return code;
}

vector<pair<int, int>> PruferDecode(vector<int> const& code) {
	// 1. Restore degrees
	int n = code.size() + 2;
	vector<int> degree(n, 1);
	for (auto v : code) degree[v]++;
	
	// 2. Find first leaf
	int ptr = 0;
	while (degree[ptr] != 1) 
		ptr++;
	int leaf = ptr;
	
	// 3. Restore code into tree
	vector<pair<int, int>> tree;
	for (auto v : code) {
		tree.emplace_back(leaf, v);
		
		// Find next leaf
		if (--degree[v] == 1 && v < ptr) leaf = v;
		else {
			ptr++;
			while (degree[ptr] != 1) ptr++;
			leaf = ptr;	
		}
	}
	tree.emplace_back(leaf, n-1);
	return tree;
}	

int main() {
  	if (getenv("LOCAL")) setIO();
    printf("Prufer code - Building\n");
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
	  a--; b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    auto prufer_code = PruferCode(adj);
    for (auto e : prufer_code) cout << e+1 << " ";
    cout << endl;
    Clean();

    printf("Prufer Code - Restoration\n");
    auto tree = PruferDecode(prufer_code);
    for (auto u : tree) cout << u.first+1 << " - " << u.second+1 << endl;
    Clean();
    return 0;	
}
