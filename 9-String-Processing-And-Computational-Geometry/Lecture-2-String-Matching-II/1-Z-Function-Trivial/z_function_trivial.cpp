#include <bits/stdc++.h>
using namespace std;

void setIO() {
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

// vector<int> z_function(string const & s) {
//     int n = (int) s.size();
//     vector<int> z(n);
//     for (int i = 1; i < n; i++) {
//         int temp = 0;
//         for (int j = i; j < n; j++) {            
//             if (s[temp] == s[j]) {
//                 ++z[i];
//                 ++temp;
//             } else {
//                 break;
//             }
//         }
//     }
//     return z;
// }

// but we can do better and reduce some variables...

vector<int> z_function(string const & s) { // still, trivial implementation
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
    }
    return z;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if(getenv("LOCAL")){setIO();}

    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        auto z = z_function(s);
        cout << "s= ";
        for (auto c : s) cout << c << " ";
        cout << endl << "Z= ";
        for (auto i : z) cout << i << " ";
        cout << endl << endl;
    }

    return 0;
}
