//順序付けされたデータを複数保持することができる順序付集合のコンテナクラス
//重複するデータを保持することはできない
set<int> s;
multiset<int> ms;
s.insert(); //要素の追加
s.erase(); //要素の削除
s.find();   //発見したらその要素へのイテレータを返す
s.count();  //要素の数を返す
s.empty();  //空ならtrue
s.size();   //要素数を返却
s.clear();  //空にする

unordered_set<int> s;
unordered_multiset<int> ms;
s.insert(); //要素の追加
s.erase(); //要素の削除
s.find();   //発見したらその要素へのイテレータを返す
s.count();  //要素の数を返す
s.empty();  //空ならtrue
s.size();   //要素数を返却
s.clear();  //空にする
