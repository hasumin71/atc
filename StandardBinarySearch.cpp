#include <bits/stdc++.h>
using namespace std;

bool P(int x){
}

int binary_search(){
  int left, right;

  while(right-left>1){
    int mid= left + (right-left)/2;
    if(P(mid))right = mid;
    else left = mid;
  }
  return right;
}

int main() {
  cout << binary_search() << endl;
}