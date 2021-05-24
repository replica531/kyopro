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

int main(){
    string s, t;
    cin >> s;
    cout << s << endl;
    s = s + t; //連結
    s == t; //比較
    string s;//文字列宣言
    char c=s[n];//n番目の文字の抽出
    s.size();//文字列の長さを取得
    s.empty();//文字列がからかどうか判定
    s1+s2;//文字列の連結
    s.substr(n);//n番目以降の文字列の分割
    s.substr(n,m);//n番目以降の文字列をm文字だけ取り出す
    s.erase(n);//n番目以降の文字列の削除
    s.erase(n,m);//n番目以降の文字列をm文字だけ削除
    s.insert(n,X);//n文字目から文字列Xを挿入
    s.find(X)//文字列の検索。該当する位置を返す
    s.replace(n,m,X);//n番目から数えてm個の文字列をXに置換

    #include<iostream>
    #include<string>
    #include <sstream>
    using namespace std;
    string s1;
    istringstream ss1;
    int p1;
    cin >> s1;
    ss1 = istringstream(s1);
    ss1 >> p1;

    //数字が入ったp1を操作
    //string型に入った数字文字列をint型に変換

    string s1 = "test";
    int N = 5;
    printf("%c", (s1[0]+N));//英文字をアルファベット順でN個後にずらして出力

    s1.push_back('2');//末尾に'2'を追加
    s1.pop_back();//末尾の文字削除
}