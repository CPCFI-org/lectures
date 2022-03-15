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

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

int main() {
    if(getenv("LOCAL")){setIO();}

    string s;
    cin >> s;

    cout << "s=" << s << endl;
    cout << "hash(s)=" << compute_hash(s) << endl;

    int n; 
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    auto groups = group_identical_strings(A);
    int i = 1;
    for (auto group : groups) {
        cout << "Group #" << i << endl;
        i++;
        for (auto string_idx : group) {
            cout << "\t" << A[string_idx] << " at idx=" << string_idx << endl;
        }
    }

    return 0;
}
