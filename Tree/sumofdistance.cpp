/*

Description
You are given a tree consisting of n nodes. d(u, v) is the distance between nodes u and v, or number of edges in between the path connecting two nodes u and v. Your task is to find the sum of distances over all possible pairs of nodes.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the sum as mentioned in the problem statement.

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
18
Note
d(1, 1) = 0, d(1, 2) = 1, d(1, 3) = 1, d(1, 4) = 2, d(1, 5) = 2
d(2, 2) = 0, d(2, 3) = 2, d(2, 4) = 3, d(2, 5) = 3
d(3, 3) = 0, d(3, 4) = 1, d(3, 5) = 1
d(4, 4) = 0, d(4, 5) = 2
d(5, 5) = 0



*/



#include <iostream>

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;

int n;
vector<int> subsz;
vector<vector<int>> adj;
void dfs(int start, int parent){
    subsz[start] = 1;
    for(auto v: adj[start]){
        if(v!=parent){
            dfs(v, start);
            subsz[start]+=subsz[v];
        }
    }
}

int main(){

    cin >> n;
    adj.resize(n+1);
    subsz.resize(n+1, 0);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    long long sum = 0;
    for(int i=1; i<=n; i++){
        sum+=(1LL*subsz[i]*(n-subsz[i]));
    }
    cout<< sum;
    return 0;
}
