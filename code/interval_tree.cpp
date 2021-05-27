#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> tree;
vector<vector<int>> ind;
vector<pair<int,int>> traj;
vector<vector<int>> traj_by_frames;


void make(int size_f){
  tree.emplace_back(1,size_f);
  int i=0;
  while(tree[i].first!=tree[i].second){
    int middle=(tree[i].first+tree[i].second)/2;
    tree.emplace_back(tree[i].first,middle);
    tree.emplace_back(middle+1,tree[i].second);
    i++;
  }
}

void input(int num){
  int s=traj[num].first;
  int g=traj[num].second;
  queue<int> q;
  q.push(0);
  while(!q.empty()){            //キューq が空でなければ
    int v = q.front();        //キューq の一番上にある要素を取り出す
    q.pop();                  //キューq の一番上にある要素を削除
    int middle=(tree[v].first+tree[v].second)/2;
    if(s<=tree[v].first&&g>=tree[v].second){
      ind[v].push_back(num);
    }
    else if(g<=middle){
      q.push(v*2+1);
    }
    else if(s>middle){
      q.push(v*2+2);
    }
    else{
      q.push(v*2+1);
      q.push(v*2+2);
    }
  }
}

void find(int f){
  int node=0;
  while(tree[node].first!=tree[node].second){
    for(int num:ind[node]){
      traj_by_frames[f].push_back(num);
    }
    int middle=(tree[node].first+tree[node].second)/2;
    if(f<=middle){
      node=2*node+1;
    }
    else{
      node=node*2+2;
    }
  }
  for(int num:ind[node]){
    traj_by_frames[f].push_back(num);
  }
}

int main(){
  cout<<"n = ";
  int n;
  cin>>n;
  cout<<endl;
  make(n);
  for(int i=0;i<tree.size();i++){
    printf("tree[%d]:",i);
    cout<<tree[i].first<<" "<<tree[i].second<<endl;
  }
  ind.assign(tree.size(), vector<int>(0));
  traj_by_frames.assign(n+1,vector<int>(0));
  traj.emplace_back(1,5);
  traj.emplace_back(5,10);
  traj.emplace_back(7,12);
  for(int i=0;i<traj.size();i++){
    input(i);
  }
  for(int i=0;i<ind.size();i++){
    printf("ind[%d]:",i);
    for(int j=0;j<ind[i].size();j++){
      cout<<ind[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i=1;i<=n;i++){
    find(i);
    printf("traj_by_frames[%d]:",i);
    for(int u:traj_by_frames[i]){
      cout<<u<<" ";
    }
    cout<<endl;
  }
}