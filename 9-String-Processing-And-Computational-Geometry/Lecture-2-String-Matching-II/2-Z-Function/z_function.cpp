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

/*
    Z function algorithm:

    1. Array z is filled with zeros
    2. The current rightmost segment is assumed to be [0,0]
    3. Inside the loop:
        4. Determine the value of z[i] (either 0 or a good approximation)
        5. Try to increase the value of z[i] using trivial algorithm
        6. Update the segment [l,r] if (i+z[i]-1 > r)

    References: https://cp-algorithms.com/string/z-function.html
*/


vector<int> z_function(const string & s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] -1 > r)
            l = i, r = i + z[i] - 1;
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
