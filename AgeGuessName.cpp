#include <bits/stdc++.h>
using namespace std;

int main(){
  cout << "start game!" << endl;
  int left=20, right=36;
  while(right-left>1){
    int mid=left+(right-left)/2;
    cout << "is the age less than "<< mid << "?(yes/no)" << endl;
    string ans;
    cin >> ans;
    if(ans=="yes") right=mid;
      else left=mid;
  }
  cout << "the age is " << left << endl;
}