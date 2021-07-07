#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    int S[k];
    for (int i = 0; i < k; i++)
        scanf("%d", &S[i]);
    for (int a = 0; a < k-5; a++)
        for (int b = 0; b < k-4; b++)
            for (int c = 0; c < k-3; c++)
                for (int d = 0; d < k-2; d++)
                    for (int e = 0; e < k-1; e++)
                        for (int f = 0; f < k; f++)
                            printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
}