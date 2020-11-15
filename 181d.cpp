//1~9の数字のみからなる数字列sが与えられます並び替えて８の倍数を作れるかどうか判定
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>; //キーと値をまとめるためのデータ型として使用されている

bool solve(string s){
    if(s.size() == 1){
        return s == "8";
    }
    if(s.size()==2){
        if(stoi(s)%8 == 0) return true; //stoiとは  文字列を数値に変換する関数
        swap(s[0],s[1]);  //swap  二つの値を入れ替え
        if(stoi(s)%8 == 0) return true;
        return false;
    }
    vector<int> cnt(10); //vectorとは？長さが変えられる配列(可長変配列)
    for(char c : s) cnt[c- '0']++; //数字の分布を求める
    for(int i = 0; i < 1000; i += 8){
        int x = i;
        vector<int> nc(10); //ncとは
        rep(j,3){
            nc[x%10]++;
            x /= 10;
        }
        bool ok = true;
        rep(j,10) if(nc[j] > cnt[j]) ok = false;
        if (ok) return true;
    }
    return false;
}
int main(){
    string s;
    cin >> s;
    if(solve(s)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}