#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Rep(i, j, n) for (ll i = (ll)(j); i <= (ll)(n); ++i)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)x.size())
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9 + 7;
const int mod = 998244353;
const ll INF = 2e15;
template <class T>
void print(const T& t) {
  cout << t << endl;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
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

int main(){
  
}
