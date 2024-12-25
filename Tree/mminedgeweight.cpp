/*

Description
You are given a weighted tree of N nodes. D(u,v) is defined as the minimum weight of edge in the simple path from u to v.  Find the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v.

Input Format
The first line of input contains one integer T (1 ≤ T ≤ 105) — the number of test cases. Then T test cases follow.
The first line of each test case contains an integer N - the number of nodes in the tree (1 ≤ N ≤ 105).
The next N-1 line of each test case contains 3 space-separated integers u, v, w  denoting that there is an edge between node u and node v of weight w. (1 ≤ u,v ≤ N), (1 ≤ w ≤ 109 ).

It is guaranteed that the sum of N over all test cases does not exceed 106.

Output Format
For each test case print the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v in a new line.

Constraints
Sample Input 1
5
5
1 2 1
2 3 5
3 4 3
4 5 2
5
1 2 5
1 3 4
2 4 1
3 5 2
5
1 2 3
2 3 4
2 4 6
3 5 1
8
1 2 4
2 3 6
2 4 1
2 5 3
3 6 1
3 7 3
3 8 1
10
1 2 10
1 3 5
1 4 9
1 5 7
2 6 10
2 7 11
3 8 9
3 9 11
3 10 15
Sample Output 1
21
23
27
53
316
Note
For the 1st test case:

D(1,2) = D(1,3) = D(1,4) = D(1,5) = 1

D(2,3) = 5, D(2,4) = 3, D(2,5) = 2

D(3,4) = 3, D(3,5) = 2

D(4,5) = 2

Summation = 21

For the second test case:

D(1,2) = 5, D(1,3) = 4, D(1,4) = 1, D(1,5) = 2

D(2,3) = 4, D(2,4) = 1, D(2,5) = 2

D(3,4) = 1, D(3,5) = 2

D(4,5) = 1

Summation = 23



*/




#include <iostream>

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define f first
#define s second
ll n;
vector<pair<ll,pair<ll,ll>>> g;
vector<ll> rnk;
vector<ll> par;

ll find(ll x)
{
    if(par[x]==x)
    {
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}
void merge(ll a,ll b)
{
    ll aa=find(a);
    ll bb=find(b);
    if(aa!=bb)
    {
        if(rnk[aa]<rnk[bb])
        {
            swap(aa,bb);
        }
        par[bb]=aa;
        rnk[aa]+=rnk[bb];
        rnk[a]=rnk[b]=rnk[bb]=rnk[aa];
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    cin>>n;

    g.resize(n-1);

    rnk.assign(n+1,1);
    par.resize(n+1);
    for(ll i=1;i<=n;i++)
    {
        par[i]=i;
    }
    for(ll i=0;i<n-1;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        g[i]={c,{a,b}};
    }
    sort(g.begin(),g.end());
    ll ans=0;
    for(ll i=n-2;i>=0;i--)
    {
      ans+=(g[i].f)*(rnk[find(g[i].s.f)]*rnk[find(g[i].s.s)]);
      merge(g[i].s.f,g[i].s.s);
    }
    cout<<ans<<endl;
    }
    



    return 0;
}