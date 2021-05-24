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

typedef int Weight;
struct Edge {  //src:辺の始点,dst:辺の終点,weight:辺の重さ
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : //辺は重さが重いものを"小さい"と定義する
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

//引数 g:隣接リスト
//戻値 total:最小全域木の重み,F:最小全域木の辺集合
pair<Weight,Edges> kruskal(const Graph &g) {
  int n = g.size();
  priority_queue<Edge> Q;
  for(int u=0;u<n;u++){
    for(auto e=g[u].begin();e!=g[u].end();++e){
      if (u < e->dst) Q.push(*e);
    }
  }
  Weight total = 0;
  Edges F;
  while ((int)F.size() < n-1 && !Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (!same(e.src, e.dst)) {    //unionfindの関数
      F.push_back(e);
      total += e.weight;
      unite(e.src, e.dst);        //unionfindの関数
    }
  }
  return pair<Weight, Edges>(total, F);
}
//使い方
int main(){
  // ...
     //UnionFindの準備(必要なら)
  // ...
  Graph g(v);    //頂点数vの空隣接リストgを生成
  // ...
  g[s].push_back(Edge(s,t,w));    //隣接リストgにsからtに向かう重さwの辺を追加
  // ...
  pair<Weight,Edges>ans=kruskal(g);    //ansにgに対しての最小全域木の重さと辺集合のpairが入る
  // ...
}