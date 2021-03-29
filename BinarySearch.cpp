#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const vector<int> a = {3,5,8,10,14,17,21,28};

int binary_search(int key){
  int left=0,right=(int)a.size()-1;
  while(right>=left){
    int mid=left+(right-left)/2;
    if(a[mid]==key) return mid; //添字を返す
    else if(a[mid]>key)right= right-1;
    else if(a[mid]<key)left= left-1;
  }
  return -1;
}
int main(){
cout << binary_search(5) << endl;
}