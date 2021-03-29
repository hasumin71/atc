#include <bits/stdc++.h>
using namespace std;

const vector<int> value = {500, 100, 50, 10,5 ,1};

int main() {
  int x;
  vector<int> a(6);
  cin >> x;
  for(int i = 0; i < 6; ++i) cin >> a[i];

  int result = 0;
  for(int i = 0; i < 6; ++i){
    int add = x /value[i];

    if(add > a[i]) add = a[i];

    x -= value[i] * add;
    result += add;
  }
  cout << result << endl;
}