#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

struct Edge{
  int to;
  long long w;
  Edge(int to, long long w) : to(to), w(w){}
};

using Graph = vector<vector<Edge>>;

int main(){
  int N,M;
  cin >> N >> M;

  Graph G(N);
  for(int i = 0; i<M; ++i){
    int a,b;
    long long w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b,w));
  }
}