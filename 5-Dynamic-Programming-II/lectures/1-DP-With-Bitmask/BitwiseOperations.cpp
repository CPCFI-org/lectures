#include <bits/stdc++.h>
using namespace std;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

void Clean() {
    printf("\n==================\n\n");
}

// ---------------------------------------------
// Start coding here
// ---------------------------------------------

void IntToBinary(int x){
    cout << "x: " << x << " => " << bitset<8>(x) << endl;
}


int main() {
    if (getenv("LOCAL")) { setIO(); }
    int a = 23;
    int b = 69;
    int c = a & b;
    cout << "AND\n";
    IntToBinary(a);
    IntToBinary(b);
    IntToBinary(c);
    Clean();

    cout << "OR\n";
    a = 23;
    b = 69;
    c = a | b;
    IntToBinary(a);
    IntToBinary(b);
    IntToBinary(c);
    Clean();

    cout << "XOR\n";
    a = 23;
    b = 69;
    c = a ^ b;
    IntToBinary(a);
    IntToBinary(b);
    IntToBinary(c);
    Clean();

    cout << "Left shift operator: << \n";
    a = 1;
    b = 7;
    c = a << b;
    printf("a: %d b: %d (a<<b): %d\n", a, b, c);
    IntToBinary(a);
    IntToBinary(c);

    a = 5;
    b = 3;
    c = a << b;
    printf("a: %d b: %d (a<<b): %d\n", a, b, c);
    IntToBinary(a);
    IntToBinary(c);
    Clean();

    cout << "Right shift operator: >>" << endl;
    a = 5;
    b = 3;
    c = a >> b;
    printf("a: %d b: %d (a >> b): %d\n", a, b, c);
    IntToBinary(a);
    IntToBinary(c);

    a = 23;
    b = 3;
    c = a >> b;
    printf("a: %d b: %d (a >> b): %d\n", a, b, c);
    IntToBinary(a);
    IntToBinary(c);
    Clean();

    cout << "Overflow\n";
    int i = 5;
    cout << (1 << i) << endl;
    i = 30;
    cout << (1 << i) << endl;
    i = 31;
    cout << (1 << i) << endl;
    cout << (1LL << i) << endl;
    i = 62;
    cout << (1LL << i) << endl;
    i = 63;
    cout << (1ULL << i) << endl;
    i = 64;
    cout << (1ULL << i) << endl;
    cout << "i = 65\n" ;
    i = 65;
    cout << (1ULL << i) << endl;
    cout << "i = 1\n" ;
    i = 1;
    cout << (1ULL << i) << endl;
    bitset<64> BA;
    cout << BA << endl;
    bitset<100> BB;
    cout << BB << endl;
    Clean();

    cout << "Avoid overflows\n";
    int x = (1 << 5) + 20;
    IntToBinary(x);
    i = 5;
    cout << ((x >> i) & 1) << endl;

    x = (1 << 3) + 20;
    IntToBinary(x);
    i = 5;
    cout << ((x >> i) & 1) << endl;
    Clean();

    /*
    Problem: If (i+1)th bit of X is ON?
    Solutions:
        1. Might cause overflows:
            - x & (1 << i)

        2. Avoids overflows:
            - (x >> i) & 1
    */
   
    cout << "Generating subsets\n";
    x = 3;
    cout << "x: " << x << endl;
    /* 
        s : Iterate from 0 up to (2^n)-1
            i: Iterate from 0 up to x
                if ith bit of S is on
                    print(1)
                else 
                    print(0)
    */ 
   for (int s = 0; s < (1<<x); s++) {
       cout << s << ": ";
       for (int i = 0; i < x; i++) {
           if (s & (1 << i)) {
               cout << 1 << " ";
           } else {
               cout << 0 << " ";
           }
       }
       cout << endl;
   }
    
    return 0;
}