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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


int main() {
    if(getenv("LOCAL")){setIO();}

    string s; 
    cin >> s;

    auto pi = prefix_function(s);
    for (auto p : pi) cout << p << " ";
    cout << endl;

    // Search fro a substring s in a string t
    cin >> s;
    string t;
    cin >> t;

    string ST = s + '#' + t;
    int n = (int) s.length();
    int m = (int) t.length();

    cout << "ST=" << ST << endl;

    auto pi_st = prefix_function(ST);
    for (int i = 0; i <= n+m; i++) {
        if (pi_st[i] == n) {
            cout << (i-2*n) << endl;
        }
    }

    return 0;
}
