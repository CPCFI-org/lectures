#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N) {
        if ((N < 2) || (N > 79)) {
            printf("There are not solutions for %d.\n\n", N);
        } else {
            bool foundSolution = false;
            for (int fghij = 1234; fghij <= 98765 / N; fghij++) {
                int abcde = fghij * N;
                int tmp, used = (fghij < 10000);
                tmp = abcde;
                /*
                    After the while loop, 'used' will store a '1' in the position
                    of each different digit in 'tmp' --> (1 << (tmp % 10))

                    tmp % 10 : integer number with the last digit of 'tmp'

                    1 << (tmp % 10) : binary number that has a 1 in the bit tmp % 10

                    used |= 1 << (tmp % 10) : binary OR between 'used' and 
                                                '1 << (tmp % 10)'
                */  
                while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
                tmp = fghij; 
                while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
                if (used == (1 << 10) - 1) { // checks if all numbers are different
                    printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
                    foundSolution = true;
                }
            }
            if (foundSolution) { cout << endl; }
            else
                printf("There are not solutions for %d.\n\n", N);
        }
        cin >> N;
    }
}