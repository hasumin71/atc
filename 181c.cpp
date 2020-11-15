#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>; //キーと値をまとめるためのデータ型として使用されている
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  rep(i,n)rep(j,i)rep(k,j){
    int a = x[j]-x[i], b = y[j]-y[i];
    int c = x[k]-x[i], d = y[k]-y[i];
    if (a*d == c*b){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}