#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void printA(vector<int> a) {
    printf("{");
    for (int ai : a)
        printf(" %d", ai);
    printf(" }\n");
}

bool isSolution(vector<int> a, int n) {
    return a.size() == n;
}

vector<int> buildInitialCandidates(int n) {
    vector<int> candidates;
    for (int i=0; i < n; i++)
        candidates.push_back(i);
    return candidates;
}

vector<int> generateCandidates(vector<int> a, int n) {
    vector<int> initialCandidates = buildInitialCandidates(n);
    if (a.size() == 0) {
        return initialCandidates;
    } else {
        vector<int> candidates;
        //vector 'a' needs to be sorted so set_difference works correctly
        sort(a.begin(), a.end());
        set_difference(
            initialCandidates.begin(), initialCandidates.end(), a.begin(), a.end(),
            inserter(candidates, candidates.begin())
        );
        return candidates;
    }
}

int backtracking(vector<int> a, int n, int sols=0) {
    if (isSolution(a, n)) {
        sols += 1;
        printA(a);
    } else {
        /*
            cout << endl << "\tA: {";
            for (auto i : a) cout << i << ' ';
            cout << '}' << endl;
        */
        vector<int> candidates = generateCandidates(a, n);
        /*
            cout << "\tCandidates: {";
            for (auto i : candidates) cout << i << ' ';
            cout << '}' << endl << endl;
        */
        for (int c : candidates) {
            a.push_back(c);
            sols = backtracking(a, n, sols);
            a.pop_back();
        }
    }
    return sols;
}

int main() {
    int n = 4;
    vector<int> a;
    int numSols = backtracking(a, n);
    printf("\nFor n=%d : %d permutations\n", n, numSols);
}