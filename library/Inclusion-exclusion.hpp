//包除定理
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#define ll long long 
using namespace std;
int main(){
    ll n;
    cin>>n;
    //素因数分解をしていきます
    ll test=n;//こうやって分けておかないとやばいです(実経験)
    vector<ll> primes;//Nの素因数を格納する配列
    for(ll prime=2;prime<sqrt(n);prime++){//√aしておかないとO(N)になる、注意！
        if(test%prime==0){
            primes.push_back(prime);//素因数を加えていく
            while(test%prime==0){
                test/=prime;
            }
        }
    }
    if(test!=1)primes.push_back(test);//忘れないように。
    //ちなみに講座前にこの問題を解いてるときこれを忘れてWA
    ll m=primes.size();
    ll res=0;
    //bit全探索を書けますか？私は書けます。
    //bitの考え方としてm=3ならbit=000~111(2)まで回すイメージ
    //2個目のforでどのbitがたっているかをcheckをするイメージ
    //とにかく書いてみましょう！！！！！！！！
    for(ll bit=1;bit<(1<<m);bit++){
        ll k=1;
        for(ll i=0;i<m;i++){//m桁まで見る
            if(bit&(1<<i)){//i番目のbitがたっているかどうか
                k*=primes[i];
            }
        }
        ll num=__builtin_popcountll(bit);//何個bitがたっているかわかる、便利！
        if(num%2==1)res+=n/k;//包徐定理の肝
        else res-=n/k;//どっちを足すか引くかに注意です！
    }
    cout<<n-res<<endl;//余事象を取っていたことを忘れずに！！
}