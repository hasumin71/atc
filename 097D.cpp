#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define mk make_pair
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
const int MAX = 2e5+5;
int N, M, p[MAX];

int find(int a) {
	if(p[a] == a) return a;
	return p[a] = find(p[a]);
}

int get(int a, bool op) {
	return a + op * N;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

void merge(int a, int b) {
	if((a = find(a)) != (b = find(b)))
		p[a] = b;
}


int main(int argc, char** argv) {
	int a, b, ans = 0;
	scanf("%d%d", &N, &M);
	rep(i, 0, MAX) p[i] = i;
	REP(i, 1, N) {
		scanf("%d", &a);
		merge(get(i, 0), get(a, 1));
	}
	rep(i, 0, M) {
		scanf("%d%d", &a, &b);
		merge(a, b);
	}
	REP(i, 1, N)
		ans += same(get(i, 0), get(i, 1));
	printf("%d\n", ans);
	return 0;
}
