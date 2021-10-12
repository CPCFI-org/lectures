/* n Queens Chess Problem */
#include <cstdlib>                       
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

int row[8], TC, a, b, lineCounter, n, ans;
bitset<30> rw, ld, rd; // for the largest n = 14, we have 27 diagonals

void backtrack(int c) {
    if (c == n) { ans++; return; }
    for (int r = 0; r < n; r++) {
        if (board[r][c] != '*' && !rw[r] && !ld[r-c+n+1] && !rd[r+c]) {
            rw[r] = ld[r-c+n+1] = rd[r+c] = true;
            backtrack(c+1);
            rw[r] = ld[r-c+n+1] = rd[r+c] = true;
        }
    }
}

int main() {
    scanf("%d %d", &a, &b); a--; b--;         // switch to 0-based indexing
    memset(row, 0, sizeof row); lineCounter = 0;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(0);           // generate all possible 8! candidate solutions
    return 0;
}