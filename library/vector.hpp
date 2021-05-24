#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define Rep(i,j,n) for (ll i=(ll)(j);i<=(ll)(n);++i)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int mod = 998244353;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

/*
ll ti=clock();
cout<<("Execution Time: %.4lf sec", 1.0 * (clock() - ti) / CLOCKS_PER_SEC)<<endl;
*/

int main(){
    vector<int> v(5);
    v.size(); //vの大きさ
    v[i]; //i番目の要素にアクセス
    v.insert(iterator、値);
    v.front();  //先頭を参照
    v.back();   //末尾を参照
    v.push_back();  //末尾に要素を追加
    v.pop_back();   //末尾の要素を削除
    v.erase(v.begin()+n-1);//n番目の要素を削除
    v.erase(v.begin()+first-1,a.begin()+last);//[first,last)を削除
    v.clear();//全ての要素を削除
    v.empty()//aが空であるかどうか
    sort(v.begin(),v.end());//昇順にソート
    reverse(v.begin(),v.end());//要素を逆順にする
    accumulate(v.begin(),v.end(),初期値);//全加算
    auto itr=find(v.begin(),v.end(),値);//最初の要素へのイテレータ取得
    count(v.begin(),v.end(),値);//値の数を返す
}