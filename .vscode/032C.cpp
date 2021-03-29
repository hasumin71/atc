#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>; //pairは二つの異なる型の値を保持する組を表現するためのクラス
using pip = pair<int, pii>;
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true); }

void solve() {
  int n; cin >> n;
  vector<pii> g(n);
  for(auto &[a,b] :g) cin >> a >> b;

  vector<int> p(n);
  iota(begin(p), end(p), 0);

  sort(begin(p), end(p), [&](int l, int r){
    return g[l] < g[r];
  });

  int MAX = 1e6;
  vector<pip> dp(MAX + 1, {1, {1, -1}});
  dp[0].first = 0;

  int now = 0, prev = 0;

  for(int i=0; i<n; ++i){
    auto &[a,b] = g[p[i]];
    while(now < a){
      if(!chmin(dp[now+1], dp[now])){
        prev = now + 1;
      }
    }
  }
}