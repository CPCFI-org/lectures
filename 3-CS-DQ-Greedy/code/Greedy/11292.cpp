#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input 
-----
n m 
n heads
m heights
-------------
2 3
5
4
7
8
4
2 1
5
5
10
0 0
*/

// n dragon heads
// m knight heights

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    while (n != 0 || m != 0) {
        int dragon[n];
        int knight[m];

        for (int i = 0; i < n; i++) scanf("%d", &dragon[i]);
        for (int i = 0; i < m; i++) scanf("%d", &knight[i]);

        sort(dragon, dragon + n);
        sort(knight, knight + m);

        int gold, d, k; //d: dragons; k: knights
        gold = d = k = 0;

        while (d < n && k < m) { //still have dragon heads or knights
            while (dragon[d] > knight[k] && k < m) k++; // find required knight
            if (k == m) break; // no knight can kill this dragon head, doomed !
            gold += knight[k];
            d++; k++;
        }

        if (d == n) printf("%d\n", gold); // all dragon heads are chopped?
        else printf("Lootwater is doomed!\n");

        scanf("%d", &n);
        scanf("%d", &m);
    }
}