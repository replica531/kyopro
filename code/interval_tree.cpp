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

void MakeTree(int max_frame){
	tree.emplace_back(0, max_frame);//フレームは0-indexed
	int i = 0;
	while (tree[i].first!=tree[i].second) {
		int middle = (tree[i].first + tree[i].second) / 2;
		tree.emplace_back(tree[i].first,middle);
		tree.emplace_back(middle + 1, tree[i].second);
		i++;
	}
  trajlist_in_tree.resize(tree.size());
}

//幅優先探索で軌跡番号をtree_indexにおいていく
void SetTrajectoryInTree(int traj_num) {
	// pair<int,int> traj = trajectories[traj_num];
	int from = trajectories[traj_num].F;
	int to = trajectories[traj_num].S;
	std::queue<int> Q;
	Q.push(0);
  // printf("from:%d, to:%d\n",from,to);//debug
	while (!Q.empty()) {
		int v = Q.front();
    // cout<<v<<endl;//debug
		Q.pop();
		int middle = (tree[v].first + tree[v].second) / 2;
		if (from <= tree[v].first&&to>=tree[v].second) {
			trajlist_in_tree[v].push_back(traj_num);
		}
		else if (to <= middle) {
			Q.push(v * 2 + 1);
		}
		else if (from > middle) {
			Q.push(v * 2 + 2);
		}
		else {
			Q.push(v * 2 + 1);
			Q.push(v * 2 + 2);
		}
	}
}

void RemoveTrajectoryFromTree(int traj_num) {
	// ASSERT(0 <= traj_num && traj_num < static_cast<int>(this->Size()));
	auto& traj = trajectories[traj_num];
	int from = traj.F;
	int to = traj.S;
	std::queue<int> Q;
	Q.push(0);
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		int middle = (tree[v].first + tree[v].second) / 2;
		if (from <= tree[v].first&&to >= tree[v].second) {
			for (int i = 0; i < trajlist_in_tree[v].size(); i++) {
				if (trajlist_in_tree[v][i] == traj_num) {
					trajlist_in_tree[v].erase(trajlist_in_tree[v].begin() + i);
				}
			}
		}
		else if (to <= middle) {
			Q.push(v * 2 + 1);
		}
		else if (from > middle) {
			Q.push(v * 2 + 2);
		}
		else {
			Q.push(v * 2 + 1);
			Q.push(v * 2 + 2);
		}
	}
}

std::vector<int> GetTrajectoriesByFrame(int frame){
	std::vector<int> trajlist_by_frame_state;
	int i = 0;
  // printf("frame:%d\n",frame);//debug
	while (tree[i].first != tree[i].second) {
    // print(i);//debug
		for (int traj_num : trajlist_in_tree[i]) {
      trajlist_by_frame_state.push_back(traj_num);
		}
		int middle = (tree[i].first + tree[i].second) / 2;
		if (frame <= middle) {
			i = i * 2 + 1;
		}
		else {
			i = i * 2 + 2;
		}
	}
	for (int traj_num : trajlist_in_tree[i]) {
    trajlist_by_frame_state.push_back(traj_num);
	}
  // for(int traj:trajlist_by_frame_state){
  //   cout<<traj<<" ";
  // }
  // cout<<endl;//debug
	return trajlist_by_frame_state;
}

int main(){
  //フレーム数fの入力
  cout<<"f = ";
  ll f;
  cin>>f;
  cout<<endl;
  //軌跡リストの作成
  trajectories.emplace_back(1,5);
  trajectories.emplace_back(5,10);
  trajectories.emplace_back(7,12);
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
  RemoveTrajectoryFromTree(0);
  for(int i=0;i<trajlist_in_tree.size();i++){
    printf("trajlist_in_tree[%d]:",i);
    for(int j=0;j<trajlist_in_tree[i].size();j++){
      cout<<trajlist_in_tree[i][j]<<" ";
    }
    cout<<endl;
  }
}