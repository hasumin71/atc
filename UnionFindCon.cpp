#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> par, siz;

  UnionFind(int n) : par(n, -1), siz(n, 1){}

  //根を求める
  int root(int x){
    if(par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }

  //xとyが同じグループに属するかどうか
  bool issame(int x, int y){
    return root(x) == root(y);
  }

  //xを含むグループとyを含むグループとを併合する
  bool unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return false;
    if(siz[x] < siz[y]) swap(x,y);
    par[y] = x;
  }
}