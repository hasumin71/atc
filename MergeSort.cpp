#include <bits/stdc++.h>
using namespace std;

//配列aの区間[left,right)をソートする
//[left,right)は、left,left+1,...,right-1番目を表す
void MergeSort(vector<int> &a, int left, int right){ //配列aの区間(left,right)をソートする
  if(right - left == 1) return; //二分探索と同じ
  int mid = left + (right - left) /2;

  //左半分[left,mid)をソート
  MergeSort(a, left, mid); //aには何が入るの？ //右と左の配列をソートした奴はどこに保管されるの？

  //右半番[mid,right)をソート
  MergeSort(a,mid,right);

  //いったん「左」と「右」のソート結果をコピーしておく(右側は左右反転) //なぜ右側は左右反転？
  vector<int> buf;
  //引数で持ってきたleft
  for(int i = left; i < mid; ++i) buf.push_back(a[i]); //push_back 要素を後ろに追加 左の配列を保管
  for(int i = right -1; i >= mid; --i) buf.push_back(a[i]); //右の配列を保管

  //併合する
  int index_left = 0; //左側の添字
  int index_right = (int)buf.size() -1; //右側の添字 //なんでキャスト？
  for(int i = left; i<right; ++i){ //leftはどこで初期化されてるの？
    //左側採用
    if(buf[index_left] <= buf[index_right]){
      a[i] = buf[index_left++];
    }
    //右側採用
    else{
      a[i] = buf[index_right--];
    }
  }
}

int main(){
  //入力
  int N; //要素数
  cin >> N;
  vector<int> a(N);
  for(int i=0; i<N; ++i) cin >> a[i];

  //マージソート
  MergeSort(a,0,N); //これが呼ばれた時にソートされるんじゃないの？
}