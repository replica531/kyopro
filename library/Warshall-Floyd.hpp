const int INF = 7+(1e+9);
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
//引数 Graph:隣接リスト,dist:各頂点から各頂点までの距離が入る,inter:最短路木の親頂点が入る
//戻値 負閉路が存在しない場合:true,そうでないとき:false
bool shortestPath(const Graph &g,vector<vector<Weight> > &dist,vector<vector<int> > &inter) {
  int n = g.size();
  dist.assign(n,vector<Weight>(n,INF));
  for(int i=0;i<n;i++){
    dist[i][i]=0;
  }
  for(int i=0;i<n;i++){
    for(auto f=g[i].begin();f!=g[i].end();f++){
      dist[i][f->dst]=f->weight;
    }
  }
  inter.assign(n, vector<int>(n,-1));
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(dist[i][k]<INF && dist[k][j]<INF && dist[i][j]>dist[i][k]+dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          inter[i][j] = k;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    if(dist[i][i]<0){
      return false;
    }
  }
  return true;
}
void buildPath(const vector<vector<int> > &inter,int s,int t,vector<int> &path) {
  int u = inter[s][t];
  if (u < 0) path.push_back(s);
  else buildPath(inter, s, u, path), buildPath(inter, u, t, path);
}

//引数 inter:最短路木の親頂点,s:始点,t:終点
//戻値 path:sからtまでの最短経路
vector<int> buildPath(const vector<vector<int> > &inter,int s,int t) {
  vector<int> path;
  buildPath(inter, s, t, path);
  path.push_back(t);
  return path;
}
//使い方
int main(){
  // ...
  Graph g(v);    //頂点数vの空隣接リストgを生成
  // ...
  g[s].push_back(Edge(s,t,w));    //隣接リストgにsからtに向かう重さwの辺を追加
  // ...
  vector<vector<Weight> >dist;
  vector<vector<int> > inter;
  bool negative_cycle=shortestPath(g,dist,inter);
  // ...
}