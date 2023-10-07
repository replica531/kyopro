#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Rep(i, j, n) for (ll i = (ll)(j); i <= (ll)(n); ++i)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9 + 7;
const int mod = 998244353;
const ll INF = 2e15;
template <class T>
void print(const T &t) {
  cout << t << endl;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

/*
ll ti=clock();
cout<<("Execution Time: %.4lf sec", 1.0 * (clock() - ti) /
CLOCKS_PER_SEC)<<endl;
*/
const int INF = 7 + (1e+9);
typedef int Weight;
struct Edge {  // src:辺の始点,dst:辺の終点,weight:辺の重さ
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) : src(src), dst(dst), weight(weight) {}
};
bool operator<(const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight
                              :  // 辺は重さが重いものを"小さい"と定義する
             e.src != f.src ? e.src < f.src
                            : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
// 引数
// g:隣接リスト,s:始点,dist:各頂点までの距離が入る(負閉路を含む場合,-INF),prev:最短路木の親頂点が入る
// 戻値 負閉路が存在しない場合:true,そうでないとき:false
bool shortestPath(const Graph &g, int s, vector<Weight> &dist,
                  vector<int> &prev) {
  int n = g.size();
  dist.assign(n, INF + INF);
  dist[s] = 0;
  prev.assign(n, -2);
  bool negative_cycle = false;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (auto e = g[i].begin(); e != g[i].end(); e++) {
        if (dist[e->dst] > dist[e->src] + e->weight) {
          dist[e->dst] = dist[e->src] + e->weight;
          prev[e->dst] = e->src;
          if (k == n - 1) {
            dist[e->dst] = -INF;
            negative_cycle = true;
          }
        }
      }
    }
  }
  return !negative_cycle;
}

// 引数 prev:最短路木の親頂点集合,t:終点
// 戻値 path:sからtへの最短経路
vector<int> buildPath(const vector<int> &prev, int t) {
  vector<int> path;
  for (int u = t; u >= 0; u = prev[u]) path.push_back(u);
  reverse(path.begin(), path.end());
  return path;
}
// 使い方
int main() {
  // ...
  Graph g(v);  // 頂点数vの空隣接リストgを生成
  // ...
  g[s].push_back(Edge(s, t, w));  // 隣接リストgにsからtに向かう重さwの辺を追加
  // ...
  vector<Weight> dist;
  vector<int> prev;
  bool negative_cycle = shortestPath(g, 0, dist, prev);
  // ...
}
