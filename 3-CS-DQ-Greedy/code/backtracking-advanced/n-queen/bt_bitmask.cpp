/* n Queens Chess Problem  -- BITMASK */
#include <cstdlib>                       
#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

/*
    Input <- n
    Output <- print one solution
*/

int rw, ld, rd, pos, n; // bitmask
vector<int> sol;

void printSol() {
    for(auto it: sol)
        cout << it << " ";
    cout << endl;
}

void backtrack(int rw) {
    if (n == pow(2, n+1)-1) {
        printSol();
        return;
    }

}

int main() {
    cin >> n;
    sol.resize(n);
    rw = 1;
    ld = 1;
    rd = 1;
    pos = pow(2, n+1)-1;
    backtrack(0);
}