#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int arr[5] = {7,7,7};   // initial size (5) and initial value {7,7,7,0,0}
  vector<int> v(5, 5);    // initial size (5) and initial value {5,5,5,5,5}

  printf("arr[2] = %d and v[2] = %d\n", arr[2], v[2]);           // 7 and 5

  for (int i = 0; i < 5; i++) {
    arr[i] = i;
    v[i] = i;
  }

  printf("arr[2] = %d and v[2] = %d\n", arr[2], v[2]);           // 2 and 2

  arr[10] = 5;     // static array will generate index out of bound error
  // uncomment the line above to see the error

  v.push_back(5);                          // but vector will resize itself
  printf("v[5] = %d\n", v[5]);                                         // 5  

  vector<int> v2;
  for (int i = 0; i < 20; i++) {
    v2.push_back(i);
  }

  for (int i = 0; i < 20; i++) {
    printf("%d ", v2[i]);
  }

  cout << "\n";

  vector<int> v3(10);

  for (int i = 0; i < 10; i++) {
    printf("%d ", v3[i]);
  }

  v3.push_back(23);
  v3.push_back(40);

  for (int i = 0; i < 12; i++) {
    printf("%d ", v3[i]);
  }

  v3.pop_back();

  cout << "\n";

  for (int i = 0; i < 11; i++) {
    printf("%d ", v3[i]);
  }

  
  return 0;
}
