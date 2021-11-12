/* n Queens Chess Problem  -- BITMASK */
#include <cstdlib>                       
#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

/*
    Input <- n
    Output <- print one solution
*/

#define setBit(S, j) (S |= (1 << j)) // S |= X ---> S = S | X
#define isOn(S, j) (S & (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))

void printSet(int vS) {  
  printf("S = %2d = ", vS);  
  stack<int> st;
  while (vS)
    st.push(vS % 2), vS /= 2;
  while (!st.empty())                        
    printf("%d", st.top()), st.pop();
  printf("\n");
}



int rw, ld, rd, pos, n; // bitmask
int ans;

void backtrack(int n, int currpos, int c) {
    setBit(rw, c);
    if (rw == (1 << n)-1) {
        // cout <<  c << endl;
        ans ++;
        return;
    } else if (currpos == n-1) {
        // cout << endl << "bqp" << endl;
        return;
    }

    // if (currpos == 0) cout << "Queens: ";
    // cout << c << " ";
    
    
    setBit(ld, c);
    ld = ld << 1;
    setBit(rd, c);
    rd = rd >> 1;
    int og_pos = (1<<n)-1;
    pos = og_pos & ~(rw | ld | rd);
    
    // printSet(rw);
    // printSet(ld);
    // printSet(rd);
    // printSet(pos);


    for(int i = 0; i < n; i++) {
      if (isOn(pos, i)) {
        currpos++;
        backtrack(n, currpos, i);
        clearBit(rw, i);
        currpos--;
      }
    }
    
}

int main() {
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++) {
      rw = 1;
      ld = 0;
      rd = 0;
      pos = (1 << n)-1;
      backtrack(n, 0, i);
    }
    cout << ans << endl;
}