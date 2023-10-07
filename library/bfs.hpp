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

//グリッド用
int dp_y[] = {1,0,-1,0};
int dp_x[] = {0,1,0,-1};

int main(){
  ll h,w;
  cin>>h>>w;
  vector<string> grid(h);
  rep(i,h){
      cin>>grid[i];
  }
  vector<vector<bool>> vec(h,vector<bool>(w,false));
  rep(i,h){
      rep(j,w){
          if(grid[i][j]=='#'){
              vec[i][j]=true;
          }
      }
  }
  queue<Pll> Q;                 //空のキューQ を用意
  vll count(h,vl(w,-1));        //移動回数
  count[0][0]=0;
  vec[0][0] = true;                // スタート地点に訪問済みの印を付ける
  Q.push(Pll(0,0));                // スタート地点をキューQ に追加
  while(!Q.empty()){            //キューQ が空でなければ
    Pll v = Q.front();        //キューQ の一番上にある要素を取り出す
    Q.pop();                  //キューQ の一番上にある要素を削除
    rep(i,4){
        if(!(v.F+dp_y[i]>=0&&v.F+dp_y[i]<h&&v.S+dp_x[i]>=0&&v.S+dp_x[i]<w)){
          continue;
        }
        else if(vec[v.F+dp_y[i]][v.S+dp_x[i]]){
          continue;
        }
        count[v.F+dp_y[i]][v.S+dp_x[i]]=count[v.F][v.S]+1;
        Q.push(Pll(v.F+dp_y[i],v.S+dp_x[i]));
        vec[v.F+dp_y[i]][v.S+dp_x[i]]=true;
    }//上下左右に対して操作
  }
  print(count[h-1][w-1]);
}
