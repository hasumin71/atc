// N個の交差点 M個の道路 道路は異なる二つの交差点を結んでいる 道路は異なる二つの交差点を結んでいる。
// ある交差点から別の交差点まで道路を使って行き来できるとは限らない。
// とある建設会社は全ての交差点を行き来できるように最小限の道路を作るようにしたいと考えている。
// すでにどの交差点からも全ての交差点に行き来できる時は0を出力させる。

//a1,b1はi番目の道路がつなぐ二つの交差点を表す二つの整数。

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> par;
    // コンストラクタ
    UnionFind(int N) : par(N){
      // iの親はiである
      for(int i = 0; i < N; i++) par[i] = i;
    }
    //データがxの木の根の場合は、xを返す。
    //データがxの木の根でない場合は、parで親を再起的にたぐり、最終的に親の値を返す
    int root(int x) { //初期値としてそれぞれが木の根になるのに、木の根ではない場合がくることはあるの？
      if(par[x] == x) return x;
      return par[x] = root(par[x]); //なぜ再起が可能？
    }
    //xとyの木を併合
    void unite(int x, int y){ //二回目は0と2が渡される
      int rx = root(x); //0 //1
      int ry = root(y); //1 //2 rootメソッドを呼ぶ
      if(rx == ry) return;
      par[ry] = rx; //[0{1},{2,3}]
    }
    //二つのデータx,yが属する木が同じならtrueを返す
    bool same(int x, int y){
      int rx = root(x);
      int ry = root(y);
      return rx == ry;
    }
};

int main(){
  int N, M; //4(交差点の数),2(道路の数)
  cin >> N >> M;

  UnionFind tree(N); //ここに渡すと //とりあえず自分自身が根になる。 [{0},{1},{2},{3}]

  for(int i = 0; i < M; i++){ //道路の数分、交差点を表す整数のセットを取得する
    int x, y; //(x=1,y=2),(x=1,y=3)
    cin >> x >> y;
    tree.unite(x-1, y-1);  //unit関数に飛ぶ
  }
  int cnt = 0;
  //Nは交差点の数
  for(int i=0; i<N; i++){
    if(!tree.same(0,i)){ //sameメソッドを呼び出す。 //falseだったら
      tree.unite(0,i); //くっつけて
      cnt++; //カウントする
    }
  }
  cout << cnt << endl;
  return 0;
}
