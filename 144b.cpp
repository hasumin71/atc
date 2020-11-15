#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  bool can = false;
  for(int i=1; i<10; i++){
    if(n%i==0 && n/i<10){
      can = true;
      break;
    }
  }
  if(can) cout << "Yes" <<endl;
  else cout << "No" << endl;
} 

