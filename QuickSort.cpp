#include <bits/stdc++.h>
using namespace std;

//配列aの区間[left,right]をソートする
//[left,right)は、left,left+1,...、right-1 番目を表す
void QuickSort(vector<int> &a, int left, int right){ //([10,12,15,3,8,17,4,1], 0, 8)
  if(right - left <= 1) return; //もし右の値よりも左の値が大きかったらそのまま返す（意味がわからない）

  int pivot_index = (left + right) /2; //適当にここでは中点とします
  int pivot = a[pivot_index]; //中点の値を変数に格納 pivot = 8
  swap(a[pivot_index], a[right -1]); //pivot と右端をswap (8と1を交換)

  int i = left; //iは左詰されたpivot 未満要素の右端を表す i=0
  for(int j = left; j<right - 1; ++j){
    if(a[j] < pivot){ //pivot未満のものがあったら左に詰めていく a[j] = 10, pivot = 8 pivotは変わることあるの？
      swap(a[i++], a[j]); //a[i++]はiを評価してからインクリメントを行います(後置インクリメント )
      //これじゃiとjの位置いつまで立っても同じじゃね？
    }
  }
  swap(a[i],a[right-1]); //pivotを適切な場所に挿入 //添字right-1がpivotよりも小さい理由はどこにあるの？ 

  //再帰的に解く
  QuickSort(a, left,i); //左半分(pivot未満)
  QuickSort(a, i+1, right); //右半分(pivot 以上)
}

int main(){
  //入力
  int N; //要素数 [10,12,15,3,8,17,4,1]
  cin >> N; //8
  vector<int>a(N);
  for(int i =0; i<N; ++i) cin >> a[i];

  //クイックソート
  QuickSort(a, 0, N); //aには要素数が入る

}