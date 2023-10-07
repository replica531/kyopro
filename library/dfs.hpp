vector<vector<int>>
    graph;  // graph[v]には頂点v につながっている頂点の集合が入っているとする
vector<bool> vec(n, false);

void dfs(int v) {  // v に関して深さ優先探索(vは頂点の番号)
  vec[v] = true;   // v に訪問済みの印を付ける

  /*   v を処理する   */

  for (int i : graph[v]) {  // v に接続している各頂点i に対し
    if (vec[i] == false) {  // i が未訪問なら
      dfs(i);               // i に関して深さ優先探索
    }
  }
}
