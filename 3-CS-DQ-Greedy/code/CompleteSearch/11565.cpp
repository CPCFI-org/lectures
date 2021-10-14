#include<iostream>
using namespace std;

int main() {
    int A = 6, B = 6, C = 14;
    bool sol; int x, y, z;
    for (x=-22; x <= 22 && !sol; x++) 
        if (x*x <= C)
            for (y = -100; y <= 100 && !sol; y++) 
                if (y != x && x*x + y*y <= C)
                    for (z = -100; z <= 100 && !sol; z++)
                        if (z != x && z != y && x + y + z == A && x*y*z == B && x*x + y*y + z*z == C) {
                                printf("%d %d %d\n", x, y, z);
                                sol = true;
                            }
}