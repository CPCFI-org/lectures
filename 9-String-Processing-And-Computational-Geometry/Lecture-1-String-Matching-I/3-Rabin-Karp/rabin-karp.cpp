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

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); // hashes of prefixes of t
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 

    long long h_s = 0; // hash of s
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; //hash of substring of length |s|
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}


int main() {
    if(getenv("LOCAL")){setIO();}

    string pattern, text;
    cin >> pattern >> text;

    cout << "pattern=" << pattern << " text=" << text << endl;

    auto ocurrences = rabin_karp(pattern, text);

    if ((int)ocurrences.size() == 0) {
        cout << "No ocurrences" << endl;
    } else {
        cout << (int)ocurrences.size() << " occurences:" << endl;
        for (auto oc : ocurrences) {
            cout << oc << endl;
        }
    }

    return 0;
}
