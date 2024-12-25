/*


Description
You are given a tree consisting exactly of 𝑛 vertices. Each vertex 𝑣 of this tree has a value 𝑎𝑣 assigned to it.

Let 𝑑𝑖𝑠𝑡(𝑥,𝑦) be the distance between the vertices 𝑥 and 𝑦. The distance between the vertices is the number of edges on the simple path between them.

Let's define the cost of the tree as the following value: firstly, let's fix some vertex of the tree. Let it be 𝑣. Then the cost of the tree is 


Your task is to calculate the maximum as well as minimum possible cost of the tree if you can choose 𝑣 arbitrarily to calculate the answer for both the case.

Input Format
The first line contains an integer T ( 1 ≤ T ≤ 10^5) - the number of test cases.

The first line of each test case contains an integer N( 1 ≤ N≤ 10^5).

The second line of each test case contains N space-separated integers  1 ≤ ai ≤ 10^5.

The next N-1 lines contain a description of an edge → ui, vi (1 ≤ ui, vi ≤ N, ui≠vi,). Vertices ui and vi are connected by an undirected edge.

It is guaranteed that sum of all N over all test cases does not exceed 10^6.

Output Format
For each test print the maximum and minimum cost in a new line.

Constraints
Sample Input 1
1
5
1 2 3 4 5
1 2
1 3
2 4
2 5
Sample Output 1
32 16


*/



#include <iostream>

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
vector<vector<ll>> g;
vector<ll> v;
vector<ll> sub;
vector<ll> indp;
vector<ll> outdp;
ll tot;
void indfs(ll node,ll par)
{
  sub[node]=v[node];
  indp[node]=0;
  for(auto x:g[node])
  {
    if(x!=par)
    {
        indfs(x,node);
        sub[node]+=sub[x];
        indp[node]+=(indp[x]+sub[x]);
    }
  }
  
}
// void indfs(int node, int par)
// {
//     indp[node] = 0;
//     subTreeSz[node] = val[node];
//     for (auto v : g[node])
//     {
//         if (v != par)
//         {
//             indfs(v, node);
//             subTreeSz[node] += subTreeSz[v];
//             indp[node] += (indp[v] + subTreeSz[v]);
//         }
//     }
// }

void outdfs(ll node, ll par)
{
    if(par==0)
    {
        outdp[node]=0;
    }
    else{
        outdp[node]=(outdp[par]+indp[par]-(indp[node]+sub[node])+(tot-sub[node]));
    }
        for(auto x:g[node])
        {
            if(x!=par)
            {
                outdfs(x,node);
            }
        }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
      cin>>n;
      //cout<<"hi";
      g.clear();
      g.resize(n+1);
      v.clear();
      v.resize(n+1);

      sub.assign(n+1,0);
      indp.assign(n+1,0);
      outdp.assign(n+1,0);
      v[0]=0;
      tot=0;
      
      for(ll i=0;i<n;i++)
      {
        cin>>v[i+1];
        tot+=v[i+1];
      }
      for(ll i=0;i<n-1;i++)
      {
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);

      }
      
      indfs(1,0);
      //cout<<"h";
      outdfs(1,0);
      ll maxi=-1e9;
      ll mini=1e18;
      for(ll i=1;i<=n;i++)
      {
        maxi=max(maxi,indp[i]+outdp[i]);
        mini=min(mini,indp[i]+outdp[i]);
      }
      cout<<maxi<<" "<<mini<<endl;

    }


    return 0;
}