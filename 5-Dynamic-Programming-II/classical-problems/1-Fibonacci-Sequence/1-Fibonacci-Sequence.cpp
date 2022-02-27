#include <bits/stdc++.h>
using namespace std;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r",  stdin);
    freopen(out_file.c_str(), "w",  stdout);
}

long long fib(long long n) {
    vector<long long> f;
    f.push_back(1); //f[0]
    f.push_back(1); //f[1]
    for (int i = 2; i <= n; i++)
        f.push_back(f[i-1] + f[i-2]);
    return f[n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    long long n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
