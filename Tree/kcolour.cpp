/*


Description
You are given a weighted tree consisting of N vertices. Vertices ui and vi are connected by an edge with weight wi.

Let's define the K-coloring of the tree as an assignment of exactly K colors to each vertex so that each color is used no more than two times. You can assume that you have infinitely many colors available. We say that an edge is saturated in the given K-coloring if its endpoints share at least one color (i.e. there exists a color that is assigned to both endpoints).

Let's also define the value of a K-coloring as the sum of weights of saturated edges.

Please calculate the maximum possible value of a K-coloring of the given tree.

Input Format
The first line contains an integer T ( 1 ≤ T ≤ 10^5) - the number of test case.

The first line of each test case contains two space-separated integers N, K ( 1 ≤ N, K ≤ 10^6).

The next N-1 lines contain a description of an edge → ui, vi, wi (1 ≤ ui, vi ≤ N, ui≠vi, 1 ≤ w ≤ 10^5). Vertices ui and vi are connected by an undirected edge of weight wi.

It is guaranteed that sum of all N over all test cases does not exceed 10^6.

Output Format
For each test case print the maximum possible value of a K-coloring of the given tree in a new line.

Constraints
Sample Input 1
10
9 3
7 4 10
6 8 1
1 3 6
2 4 10
2 9 1
5 4 9
3 6 5
1 2 5
2 6
1 2 2
2 4
1 2 8
7 7
4 3 2
6 5 1
3 2 3
3 5 7
7 1 10
1 2 9
3 9
3 2 6
2 1 8
7 10
1 5 9
3 4 2
1 3 6
7 3 9
3 6 3
1 2 3
6 3
2 1 4
4 2 10
3 5 2
3 1 5
2 6 5
1 2
9 8
4 7 7
4 6 2
2 9 9
2 3 5
5 3 3
8 2 2
2 1 1
1 4 4
7 4
7 1 2
1 2 8
2 5 2
2 3 9
2 4 7
5 6 1
Sample Output 1
47
2
8
32
14
32
26
0
33
29


*/



#include <iostream>

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long
//0 means not connceted with parent and 1 means connected 
vector<vector<pair<int,int>>> g;
int dp[1000010][2];int k;int n;

void dfs(int node,int par)
    {
        int ans=0;dp[node][1]=0;
        dp[node][0]=0;vector<int> delta;
        for (auto c:g[node]) 
            {
                if (c.first==par) continue;

                dfs(c.first,node);
                int a=dp[c.first][0];
                int b=dp[c.first][1];

                delta.push_back(c.second+b-a);
                ans+=a;
            }

sort(delta.begin(),delta.end());
//delta.push_back(0);
reverse(delta.begin(),delta.end());
int d=delta.size();

for (int i=0;i<d;i++)
        {
    

            if (i<k-1&&delta[i]>0)
            ans+=delta[i];
            else break;
        }

       
                dp[node][1]=ans;
          
                if (k-1<d&&delta[k-1]>0)    ans+=delta[k-1];    
                dp[node][0]=ans;

            /*    for (int ch=0;ch<d;ch++)
                    {
                        ans+=delta[ch];
                        if (ch==k)
                            {
                                dp[node][0]=max(dp[node][0],ans);
                                break;
                            }

                            dp[node][1]=max(dp[node][1],ans);
                            dp[node][0]=max(dp[node][0],ans);
                    }*/
            

    }




void solve() {
  
   int n;cin>>n;cin>>k;
   g.clear();
g.resize(n+1);




   for (int i=0;i<n-1;i++)
    {
        int u,v;cin>>u>>v;int a;cin>>a;
        g[u].push_back({v,a});
        g[v].push_back({u,a});
    }
        
dfs(1,0);
    cout<<dp[1][0]<<endl;
    
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}