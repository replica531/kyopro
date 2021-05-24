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

int main() {
  ll n;
  cin>>n;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
  do {
    for(auto x : v) cout << x << " "; cout << "\n";    // v の要素を表示
  } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成

  vector<int> v{3, 2, 1};    // 要素が降順に並んだ順列
  do {
    for(auto x : v) cout << x << " "; cout << "\n";    // v の要素を表示
  } while( prev_permutation(v.begin(), v.end()) );     // 前の順列を生成
}