#include <iostream>
#include <math.h>
using namespace std;

#define EPS 1e-9

bool can(double f) {
    // return true if the jeep can reach goal state with fuel tank capacity f
    // return false otherwise
}

int main() {
    // Binary Search the Answer
    double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
    while (fabs(hi - lo) > EPS) {
        mid = (lo + hi) / 2.0;
        if (can(mid)) { 
            ans = mid; 
            hi = mid; 
        } else {
            lo = mid;
        }
    }
    printf("%.3lf\n", ans);
    return 0;
}