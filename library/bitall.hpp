
// nビットのビット列をすべて列挙する
//　nには具体的な値をいれる
for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
  bitset<ビット数> bit_q(tmp);
  for(int i=0;i<ビット数;i++){
      if(bit_q[i]){
          //処理
      }
  }
  // ビット列を出力
  cout << s << endl;
}