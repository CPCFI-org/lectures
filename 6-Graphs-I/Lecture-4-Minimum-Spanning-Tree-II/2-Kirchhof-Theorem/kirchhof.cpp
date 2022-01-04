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
// Start coding here: Kirchhof's Theorem
// ---------------------------------------------

const double EPS = 1E-9;
int n, m;
vector<vector<int>> adj, deg_mat; // adjacency matrix A and degree matrix D
vector<vector<int>> L; // Laplacian matrix: L = D - A

int Gauss(vector<vector<int>> a) {
    double det = 1;
    n = a.size();
    for (int i=0; i<n; ++i) {
        int k = i;
        for (int j=i+1; j<n; ++j)
            if (abs (a[j][i]) > abs (a[k][i]))
                k = j;
        if (abs (a[k][i]) < EPS) {
            det = 0;
            break;
        }
        swap (a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j=i+1; j<n; ++j)
            a[i][j] /= a[i][i];
        for (int j=0; j<n; ++j)
            if (j != i && abs (a[j][i]) > EPS)
                for (int k=i+1; k<n; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }
    return det;
}

int main() {
    if (getenv("LOCAL")) { setIO(); }
    printf("Kirchhof's Theorem for counting the number of spanning trees\n");
    cin >> n >> m;
    adj.resize(n, vector<int>(n));
    deg_mat.resize(n, vector<int>(n));
    L.resize(n, vector<int>(n));
    for (int i =0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
        deg_mat[a][a]++; deg_mat[b][b]++;
    }
    debug(adj);
    debug(deg_mat);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            L[i][j] = deg_mat[i][j] - adj[i][j];
    debug(L);
    vector<vector<int>> cofactor(n-1, vector<int>(n-1));
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            cofactor[i-1][j-1] = L[i][j];
    debug(cofactor);
    auto det = Gauss(cofactor);
    printf("Number of spanning trees in G: %d\n", det);
    Clean();
    return 0;
}