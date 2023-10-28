#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;

ll power(ll a,ll b){
  ll x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

ll modular_inverse(ll n, ll mod){
  return power(n,mod-2);
}

int main(){
  ll bunbo = modular_inverse(5926, mod);
  cout << 3141 * bunbo % mod << endl;
}
