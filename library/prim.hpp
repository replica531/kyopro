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

//引数 g:隣接リスト,r:最小全域木の始点
//戻値 total:最小全域木の重み,T:最小全域木の辺集合
pair<Weight, Edges> prim(const Graph &g, int r = 0) {
  int n = g.size();
  Edges T;
  Weight total = 0;
  vector<bool> visited(n);
  priority_queue<Edge> Q;
  Q.push( Edge(-1, r, 0) );    //始め、-1とrを結ぶ辺があると考える
  while (!Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (visited[e.dst]) continue;
    T.push_back(e);
    total += e.weight;
    visited[e.dst] = true;
    for(auto f=g[e.dst].begin();f!=g[e.dst].end();++f) if(!visited[f->dst]) Q.push(*f);
  }
  return pair<Weight, Edges>(total, T);
}
int main(){
  // ...
  Graph g(v);    //頂点数vの空隣接リストgを生成
  // ...
  g[s].push_back(Edge(s,t,w));    //隣接リストgにsからtに向かう重さwの辺を追加
  // ...
  pair<Weight,Edges>ans=prim(g);    //ansにgに対しての最小全域木の重さと辺集合のpairが入る
  // ...
}