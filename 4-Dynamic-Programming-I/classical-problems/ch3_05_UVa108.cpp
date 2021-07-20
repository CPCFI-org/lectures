// Maximum Sum

/*
#include <algorithm>
#include <cstdio>
using namespace std;

int n, A[101][101], maxSubRect, subRect;

int main() {     // O(n^3) 1D DP + greedy (Kadane's) solution, 0.008 s in UVa
  scanf("%d", &n);                    // the dimension of input square matrix
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    scanf("%d", &A[i][j]);
    if (j > 0) A[i][j] += A[i][j - 1];      // only add columns of this row i
  }

  maxSubRect = -127*100*100;    // the lowest possible value for this problem
  for (int l = 0; l < n; l++) for (int r = l; r < n; r++) {
    subRect = 0;
    for (int row = 0; row < n; row++) {
      // Max 1D Range Sum on columns of this row i
      if (l > 0) subRect += A[row][r] - A[row][l - 1];
      else       subRect += A[row][r];

      // Kadane's algorithm on rows
      if (subRect < 0) subRect = 0;     // greedy, restart if running sum < 0
      maxSubRect = max(maxSubRect, subRect);
  } }

  printf("%d\n", maxSubRect);
  return 0;
}

*/
        


#include <algorithm>
#include <cstdio>
using namespace std;

int n, A[101][101], maxSubRect, subRect;

int main() {                            // O(n^4) DP solution, ~0.076s in UVa
  scanf("%d", &n);                    // the dimension of input square matrix
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    scanf("%d", &A[i][j]);
    if (i > 0) A[i][j] += A[i - 1][j];           // if possible, add from top
    if (j > 0) A[i][j] += A[i][j - 1];          // if possible, add from left
    if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];     // avoid double count
  }                                          // inclusion-exclusion principle

  maxSubRect = -127*100*100;    // the lowest possible value for this problem
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coordinate
    for (int k = i; k < n; k++) for (int l = j; l < n; l++) {    // end coord
      subRect = A[k][l];      // sum of all items from (0, 0) to (k, l): O(1)
      if (i > 0) subRect -= A[i - 1][l];                              // O(1)
      if (j > 0) subRect -= A[k][j - 1];                              // O(1)
      if (i > 0 && j > 0) subRect += A[i - 1][j - 1];                 // O(1)
      maxSubRect = max(maxSubRect, subRect); }          // the answer is here

  printf("%d\n", maxSubRect);
  return 0;
}




/*

#include <algorithm>
#include <cstdio>
using namespace std;

int n, A[101][101], maxSubRect, subRect;

int main() {                // O(n^6) brute force solution, TLE (> 3s) in UVa
  scanf("%d", &n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    scanf("%d", &A[i][j]);

  maxSubRect = -127*100*100;    // the lowest possible value for this problem
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) // start coordinate
    for (int k = i; k < n; k++) for (int l = j; l < n; l++) {    // end coord
      subRect = 0;                         // sum items in this sub-rectangle
      for (int a = i; a <= k; a++) for (int b = j; b <= l; b++)
        subRect += A[a][b];
      maxSubRect = max(maxSubRect, subRect); }          // the answer is here

  printf("%d\n", maxSubRect);
  return 0;
}

*/
