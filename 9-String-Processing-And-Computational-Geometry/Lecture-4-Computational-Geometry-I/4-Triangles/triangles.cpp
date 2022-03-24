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



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if(getenv("LOCAL")){setIO();}
    return 0;
}
