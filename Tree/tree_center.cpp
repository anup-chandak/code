/*


Description
You are given a tree consisting of n nodes. Find the center of a tree. If there exist multiple centers, print -1.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the center of a tree. If there exist multiple centers, print -1.

Constraints
1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
3
1 2
1 3
Sample Output 1
1


*/



#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> g[200200];
int dep[200200];
int par[200200];
void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    for(auto v:g[node]){
        // here we are traversing all the child node of node
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}
void solve(){
  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  // first find the diameter if dia is odd then 
  dfs(1,0,0);
  int maxch=1;
  for(int i=1;i<=n;i++){
    if(dep[i]>dep[maxch]){
        maxch=i;
    }
  }
  dfs(maxch,0,0);
  for(int i=1;i<=n;i++){
    if(dep[i]>dep[maxch]){
        maxch=i;
    }
  }
  int d=dep[maxch];
  if(d%2==1){
    cout<<"-1"<<endl;
  }else{
    int node=maxch;
    int temp=d/2;
    while(temp--){
        node=par[node];
    }
    cout<<node<<endl;
  }
}
signed main(){
    solve();
}