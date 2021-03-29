#include <bits/stdc++.h>
using namespace std;

//UnionFind
struct UnionFind{
  vector<int> par,siz;

  //初期化
  UnionFind(int n) : par(n, -1), siz(n, 1){} //第一引数は要素数, 第二引数は全ての値を-1
  

  //根を求める
  int root(int x){
    if(par[x] == -1)return x; //xが根の場合はxを返す
    else return par[x] = root(par[x]);
  }

  //xとyが同じグループに属するかどうか(ネガ一致するかどうか)
  bool issame(int x, int y){
    return root(x) == root(y);
  }

  //xを含むグループとyを含むグループとを併合する
  bool unite(int x, int y){
    x= root(x); y = root(y);

    //すでに同じグループの時は何もしない
    if(x==y) return false;

    //union by size (y側のサイズがちいさくなるようにする)
    if(siz[x] < siz[y]) swap(x,y);

    //yをxの子とする
    par[y] = x;
    siz[x] += siz[y];
    return true; 
  }

  //xを含むグループのサイズ
  int size(int x){
    return siz[root(x)];
  }
};

int main(){
  UnionFind uf(7); //{0},{1},{3},{4},{5},{6}

  uf.unite(1,2); //{0},{1,2},{3},{4},{5},{6}
  uf.unite(2,3); //{0},{1,2,3},{4},{5,6}
  cout << uf.issame(1,3) << endl; //true
  cout << uf.issame(2,5) << endl; //false

  uf.unite(1,6); //{0},{1,2,3,5,6},{4}
  cout << uf.issame(2,5) << endl; //true
}