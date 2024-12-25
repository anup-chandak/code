/*

Description
You are given a tree with n vertices and a positive number k. Find the number of distinct pairs of the vertices that have a distance of exactly k between them. Note that pairs (v, u) and (u, v) are considered to be the same pair.

The distance between two vertices of a tree is the length (in edges) of the shortest path between these vertices.

 

Input Format
The first line contains an integer T ( 1 ≤ T ≤ 10^5) - the number of test cases.

The first line of each test case contains two space-separated integers N, K ( 1 ≤ N≤ 10^5, 1 ≤ K ≤ 500).

The next N-1 lines contain a description of an edge → ui, vi (1 ≤ ui, vi ≤ N, ui≠vi,). Vertices ui and vi are connected by an undirected edge.

It is guaranteed that sum of all N over all test cases does not exceed 10^5.

Output Format
For each test case print the number of distinct pairs of the tree's vertices which have a distance of exactly k between them in a new line.

Constraints
Sample Input 1
2
10 3
2 1
3 1
4 3
5 4
6 5
7 1
8 6
9 2
10 6
10 2
2 1
3 1
4 3
5 4
6 5
7 1
8 6
9 2
10 6
Sample Output 1
8
10



*/



#include <iostream>

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long
int dp[100001][501];
int n,k;int sum;
vector<vector<int>> graph;


void dfs(int node,int par)  
{
    dp[node][0]=1;
    for (auto c:graph[node])
        {
            if (par==c)  continue;
            dfs(c,node);

            for (int i=0;i<=k;i++)
                {
                    if (i+1<=k)
                    dp[node][i+1]+=dp[c][i];
                }


        for (int i=0;i<=(k-2)/2;i++){
            if (i==(k-2)-i)
                {
                    sum-=(dp[c][i]*(dp[c][i]-1))/2;
                }

                else    {
                        sum-=dp[c][i]*dp[c][k-2-i];
                }
        }
        }


        for (int i=0;i<=k/2;i++)
            {
               // sum+=dp[node][i]*dp[node][k-i];

                if (i==k-i)
                    {
                        sum+=((dp[node][i])*(dp[node][i]-1))/2;
                    }

                else
                    {
                        sum+=dp[node][i]*dp[node][k-i];
                    }
            
            }

}

void solve() {
    cin>>n>>k;
   graph.clear();
  graph.resize(n+1);
  for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
  //cout<<"hei";
  for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=k;j++)dp[i][j]=0;
    }
      //   memset(dp, 0, sizeof(dp)); 
sum=0;
       dfs(1,0);  
    cout<<sum<<endl;

    //cout<<"hi";
    
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int  t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}