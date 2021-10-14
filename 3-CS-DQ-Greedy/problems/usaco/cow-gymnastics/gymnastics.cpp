#include <iostream>
#include <string>
#include <vector>
using namespace std; 

/*

K=1 {(4,1), ...}

K=2 {(4,1), ...}

K=3 {(4,1), ...}

*/

void solve() {
    int k, n;
    cin >> k >> n;

    vector<pair<int, int>> S;

    for (int session=0; session < k; session++) {
        vector<pair<int, int>> V;

        vector<int> cows(n);
        for(int i=0; i<n;i++) cin >> cows[i];

        for(int i=0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                pair<int, int> p = make_pair(cows[i], cows[j]);
                V.push_back(p);
                if(!session) S.push_back(p);
            }
        }

        if (session) {
            vector<pair<int, int>> temp;
            for(auto v : V) {
                for (auto s : S) {
                    if (v == s) {
                        temp.push_back(v);
                        break;
                    }
                }
            }
            S = temp;
        }
    }
    cout << S.size() << endl;
}

int main() {

    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    freopen((file + "in").c_str(), "r", stdin);
    freopen((file + "out").c_str(), "w", stdout);

    solve();

}