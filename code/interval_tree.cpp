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
#define eb emplace_back
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
std::vector<std::pair<int, int>> tree; //各ノードに対応する区間の左端と右端の値(閉区間)
std::vector<std::vector<int>> trajlist_in_tree;
vector<pair<int,int>> trajectories;

void MakeTree(int video_length) {
  int tree_length=1;
  while (tree_length<video_length) {
    tree_length *= 2;
  }
  trajlist_in_tree.resize(tree_length*2);//1-indexed
}

//幅優先探索で軌跡番号をtree_indexにおいていく
void SetTrajectoryInTree(int traj_num) {
  auto& traj = trajectories[traj_num];
  int l = traj.first;
  int r = traj.second;
  int tree_length = trajlist_in_tree.size() / 2;
  l += tree_length;
  r += tree_length+1;
  while (l != r) {
    printf("l:%d,r:%d\n",l,r);
    if (l & 1){
      trajlist_in_tree[l++].push_back(traj_num);
    }
    if (r & 1){
      trajlist_in_tree[--r].push_back(traj_num);
    }
    l /= 2;
    r /= 2;
  }
}

void RemoveTrajectoryFromTree(int traj_num) {
  auto& traj = trajectories[traj_num];
  int l = traj.first;
  int r = traj.second;
  int tree_length = trajlist_in_tree.size() / 2;
  l += tree_length;
  r += tree_length+1;
  while (l != r) {
    printf("l:%d,r:%d\n",l,r);
    if (l & 1) {
      printf("l:%d",l);
      trajlist_in_tree[l].erase(find(trajlist_in_tree[l].begin(), trajlist_in_tree[l].end(), traj_num));
      l++;
    }
    if (r & 1) {
      r--;
      printf("r:%d",r);
      trajlist_in_tree[r].erase(find(trajlist_in_tree[r].begin(), trajlist_in_tree[r].end(), traj_num));
    }
    l /= 2;
    r /= 2;
  }
}

std::vector<int> GetTrajectoriesByFrame(int frame) {
  std::vector<int> trajlist_by_frame_state;
  int tree_length = trajlist_in_tree.size() / 2;
  int node = frame + tree_length;
  while (node) {
    for (int traj_num : trajlist_in_tree[node]) {
      trajlist_by_frame_state.push_back(traj_num);
    }
    node /= 2;
  }
  return trajlist_by_frame_state;
}

int main(){
  //フレーム数fの入力
  cout<<"f = ";
  ll f;
  cin>>f;
  cout<<endl;
  //軌跡リストの作成
  trajectories.emplace_back(0,8);
  trajectories.emplace_back(1,1);
  trajectories.emplace_back(2,10);
  //区間木の作成
  MakeTree(f);
  //区間木の確認
  rep(i,sz(tree)){
    printf("tree[%d]:(%d,%d)\n",i,tree[i].F,tree[i].S);
  }
  //軌跡を区間木にset
  rep(i,sz(trajectories)){
    SetTrajectoryInTree(i);
  }
  //trajlist_in_treeの確認
  for(int i=0;i<trajlist_in_tree.size();i++){
    printf("trajlist_in_tree[%d]:",i);
    for(int j=0;j<trajlist_in_tree[i].size();j++){
      cout<<trajlist_in_tree[i][j]<<" ";
    }
    cout<<endl;
  }
  //各フレームの軌跡リストを出力
  rep(i,f+1){
    vector<int> a=GetTrajectoriesByFrame(i);
    printf("trajectoriesOnFrame[%d]:",i);
    rep(i,sz(a)){
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
  //軌跡を区間木から削除
  RemoveTrajectoryFromTree(1);
  for(int i=0;i<trajlist_in_tree.size();i++){
    printf("Removed:trajlist_in_tree[%d]:",i);
    for(int j=0;j<trajlist_in_tree[i].size();j++){
      cout<<trajlist_in_tree[i][j]<<" ";
    }
    cout<<endl;
  }
}