#include <iostream>
using namespace std;

int func(int N){
  cout << "func("<< N <<")を呼び出しました" << endl;

  if(N == 0) return 0;

  //再起的に答えを求めて出力する
  int result = N + func(N-1);
  cout << N << "までの和 = " << result << endl;

  return result;
}

int main() {
  func(5);
}