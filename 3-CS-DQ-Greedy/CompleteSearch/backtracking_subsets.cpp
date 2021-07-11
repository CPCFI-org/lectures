#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printA(vector<int> a) {
    printf("{");
    for (int ai : a)
        printf(" %d", ai);
    printf(" }\n");
}

vector<int> build_candidates(int first, int n) {
    vector<int> c;
    for (int i = first; i <= n; i++) 
        c.push_back(i);
    return c;
}

int backtrack(int n, vector<int> a, int sols) {
    printA(a);
    sols += 1;
    int first;
    if (a.size() == 0) 
        first = 1;
    else 
        first = *max_element(a.begin(), a.end()) + 1;
    vector<int> candidates = build_candidates(first, n);
    for (int c : candidates) {
        a.push_back(c);
        sols = backtrack(n, a, sols);
        a.pop_back();
    }
    return sols;
}

int main() {
    int n = 4;
    vector<int> a;
    int sols = backtrack(n, a, 0);
    printf("Number of solutions for n=%d : %d\n", n, sols);
}