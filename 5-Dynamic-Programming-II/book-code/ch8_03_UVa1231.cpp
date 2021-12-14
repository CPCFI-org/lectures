// ACORN, UVa 1231, LA 4106

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int i, j, c, t, h, f, a, n, acorn[2010][2010], dp[2010];

  /*
    Input
    1 --> num of test cases 
    3 10 2 --> t, h, f
    3 1 4 10
    6 3 5 7 8 9 9
    5 3 4 5 6 9
    0
  */

  scanf("%d", &c);
  while (c--) {
    scanf("%d %d %d", &t, &h, &f);
    memset(acorn, 0, sizeof acorn);
    for (i = 0; i < t; i++) {
      scanf("%d", &a);
      for (j = 0; j < a; j++) {
        scanf("%d", &n);
        acorn[i][n]++; // there is an acorn here
      }
    }

    for (int tree = 0; tree < t; tree++) // initialization
      dp[h] = max(dp[h], acorn[tree][h]);

    for (int height = h - 1; height >= 0; height--) {
      for (int tree = 0; tree < t; tree++) {
        acorn[tree][height] += max(
            acorn[tree][height + 1], // coming from the current tree
            ((height + f <= h) ? dp[height + f] : 0) // coming from another tree
        );
        
        dp[height] = max(dp[height], acorn[tree][height]);
      }
    }
    printf("%d\n", dp[0]); // solution will be here
  }

  return 0;
}
