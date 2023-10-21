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

5
1 9 
1 9
1 9
8 1
7 2
