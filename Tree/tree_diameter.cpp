
/*

 Description
You are given a tree consisting of n nodes. The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the diameter of the tree.

Constraints
1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5
1 2
1 3
3 4
3 5
Sample Output 1
3
Note
The diameter corresponds to the path 2→1→3→5.

 */








// Write your code here
// You can set your Template at profile settings [https://maang.in/profile/template-code]
#include <iostream>
#include "bitsStdcpp.hpp" 
//#include "./stdc++.h"
//#include<bits/stdc++.h>
using namespace std;

// #define int long long

vector<vector<int>> g;
vector<int> depth, parent;

void dfs(int node, int par, int dep){
    depth[node]=dep;
    parent[node]=par;
    for(auto v:g[node]){
        if(v!=par) dfs(v, node, dep+1);
    }
}

signed main(){
    int n;
    cin>>n;
    g.resize(n+1);
    depth.assign(n+1, 0); parent.assign(n+1, 0);
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0);
    int maxdist=1;
    for(int i=2;i<=n;i++){
        if(depth[i]>depth[maxdist]){
            maxdist=i;
        }
    }
    dfs(maxdist, 0, 0);
    maxdist=1;
    for(int i=2;i<=n;i++){
        if(depth[i]>depth[maxdist]){
            maxdist=i;
        }
    }
    cout<<depth[maxdist]<<"\n";
}
