using ll = long long;

const ll INF = 2e15;
typedef ll Weight;
struct Edge {  //src:辺の始点,dst:辺の終点,weight:辺の重さ
  ll src, dst;
  Weight weight;
  Edge(ll src, ll dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : //辺は重さが重いものを"小さい"と定義する
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
//引数 g:隣接リスト,s:始点,dist:各頂点までの距離が入る,prev:最短路木の親頂点が入る
//戻値 なし
void shortestPath(const Graph &g,ll s,vector<Weight> &dist,vector<ll> &prev) {
  ll n = g.size();
  dist.assign(n, INF); dist[s] = 0;
  prev.assign(n, -1);
  priority_queue<Edge> Q;
  Q.push(Edge(-2, s, 0));
  while(!Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (prev[e.dst] != -1) continue;
    prev[e.dst] = e.src;
    for(auto f=g[e.dst].begin();f!=g[e.dst].end();f++){
      if (dist[f->dst] > e.weight+f->weight) {
        dist[f->dst] = e.weight+f->weight;
        Q.push(Edge(f->src, f->dst, e.weight+f->weight));
      }
    }
  }
}

//引数 prev:最短路木の親頂点集合,t:終点
//戻値 path:sからtへの最短経路
vector<ll> buildPath(const vector<ll> &prev, ll t) {
  vector<ll> path;
  for (ll u = t; u
   >= 0; u = prev[u])
    path.push_back(u);
  reverse(path.begin(), path.end());
  return path;
}
使い方
int main(){
  // ...
  Graph g(v);    //頂点数vの空隣接リストgを生成
  // ...
  g[s].push_back(Edge(s,t,w));    //隣接リストgにsからtに向かう重さwの辺を追加
  // ...
  vector<Weight> dist;
  vector<ll> prev;
  shortestPath(g,0,dist,prev);
  //distの中身が始点からの最短距離になる
  // ...
}
