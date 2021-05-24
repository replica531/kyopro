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

struct union_find{//rank,経路圧縮で高速化
  vector<int> par;//parは添字の親（または自分が根の時自身）を示す。
  vector<int> rank;//rankは木の高さ（根についてのみ実装,0-indexed）
  vector<int> Size;//sizeは添字と同じ親を持つ要素の数
  union_find(int sz){//コンストラクタ,sz個のノードを作成し、自分を親につける
    par.resize(sz);
    rank.assign(sz,0); //rankは最初0
    Size.assign(sz,1); //sizeは最初0
    for(int i = 0;i < sz;++i) par[i]=i;
  }
  int find(int a){//根を探す
    if(par[a]==a) return a; //親が自身を指す時、根である
    else return par[a] = find(par[a]);//根に直接つける
  }
  void unite(int a,int b){//小さい方の木の根に大きい方の根を上書きする
    int root_a,root_b;
    root_a = find(a),root_b = find(b);
    if(rank[root_a]>rank[root_b]){ //rankの高い方の根に低い方の根をつける
      par[root_b] = root_a;
      Size[root_a]+=Size[root_b];
    }else if(rank[root_a]<rank[root_b]){
      par[root_a] = root_b;
      Size[root_b]+=Size[root_a];
    }else{ //rankが同じ時、適当な方につけ、つけられた方のrankを1増やす
      rank[root_a]++;
      par[root_b] = root_a;
      Size[root_a]+=Size[root_b];
    }
  }
  bool same(int a,int b){return find(a)==find(b);}
  int size(int a){return Size[find(a)];}
};

int main(){
  ll n;
  cin>>n;
  union_find tree(n);
  tree.unite(a,b);
}
