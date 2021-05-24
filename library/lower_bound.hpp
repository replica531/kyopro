#include <bits/stdc++.h>
using namespace std;
//O(logN)
//指定した要素以上の最初の値を返す
#define all(a)  (a).begin(),(a).end()

int main() {

    //ソートする必要がある
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};

    //イテレータを返す
    auto Iter = lower_bound(all(a), 4);


    //値の表示
    cout << "----------value----------" << endl;
    cout << "Iter = " << *Iter << endl; //Iter = 4

    //先頭からの距離
    cout << "----------from----------" << endl;
    cout << "Iter = " << Iter - a.begin() << endl; //Iter = 1


    //末尾までの距離
    cout << "----------to----------" << endl;
    cout << "Iter = " << a.end() - Iter << endl; //Iter = 9


    return 0;
}
