// 負閉路が存在しない 即ち最短距離が求まっている場合: true
bool warshallFloyd(vector<vector<long long>>& d){
  int V = d.size();
  for(int k = 0; k < V; ++k){
    for(int i = 0; i < V; ++i){
      for(int j = 0; j < V; ++j){
        if(d[i][k] < INF && d[k][j] < INF && d[i][j] > d[i][k] + d[k][j]){
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  for(int i = 0; i < V; ++i){
    if(d[i][i] < 0){
      return false;
    }
  }
  return true;
}