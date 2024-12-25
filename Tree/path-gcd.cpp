/*

Description
Given a tree of N nodes and an array A of length N corresponding to the value of the nodes.

You have to answer Q queries. In each query, two nodes are given x, y→ find the gcd of nodes present on the shortest path from x to y.

Input Format
The first line contains an integer T (1 ≤ T ≤ 10000) - the number of test cases.

The second line of each test case contains two space-separated integers N (1 ≤ N ≤ 10^5).

The next line contains N space-separated integers denoting the value of the nodes. (1 ≤ A[i] ≤ 10^6).

The next N-1 lines contain two space-separated integers u, v (1 ≤ u, v ≤ N) denoting there is an undirected edge between node u and node v.

The next line contains an integer Q (1 ≤ Q ≤ 10^5).

The next Q lines contain three space-separated integers x, y (1 ≤ x, y ≤ N).

Sum of N+Q across all test cases ≤ 2*10^6.

Output Format
For each query print the output in a new line.

Constraints
Sample Input 1
2
5
2 4 5 10 6
1 2
2 3
3 4
4 5
5
1 2
2 5
4 5
3 4
4 5
5
5 10 15 10 10
1 2
2 3
3 4
3 5
10
1 2
1 3
2 4
2 5
3 5
3 4
4 1
4 5
5 1
2 3
Sample Output 1
2
1
2
5
2
5
5
5
5
5
5
5
5
5
5



*/



#include <iostream>

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const long long int infl = 1e18;
const int MOD = 1e9 + 7;

#define endl '\n'
vector<vector<long long int>> adj;
vector<vector<pair<long long int, long long int>>> par;
vector<long long int> v(100100);
vector<long long int> depth;
void dfs(long long int node, long long int prev, long long int dep)
{
    par[node][0] = {prev, __gcd(v[node], v[prev])};
    depth[node] = dep;
    for (long long int i = 1; i < 20; i++)
    {
        long long int a = par[node][i - 1].first;  // the node
        long long int b = par[node][i - 1].second; // the gcd
        long long int x = __gcd(par[a][i - 1].second, b);
        par[node][i] = {par[a][i - 1].first, x};
    }
    for (auto u : adj[node])
    {
        if (u != prev)
        {
            dfs(u, node, dep + 1);
        }
    }
}

long long int find_lca(long long int a, long long int b)
{
    long long int hcf = __gcd(v[a], v[b]);

    if (depth[a] > depth[b])
        swap(a, b);
    // always make a closer to root
    for (long long int i = 19; i >= 0; i--)
    {
        if ((depth[b] - depth[a]) & (1 << i))
        {

            hcf = __gcd(par[b][i].second, hcf);
            b = par[b][i].first;
        }
    }

    if (a == b)
        return hcf;
    else
    {
        for (long long int i = 19; i >= 0; i--)
        {
            if (par[a][i].first != par[b][i].first)
            {
                hcf = __gcd(par[b][i].second, hcf);
                hcf = __gcd(par[a][i].second, hcf);
                b = par[b][i].first;
                a = par[a][i].first;
            }
        }
        hcf = __gcd(hcf, par[a][0].second);
        return hcf;
    }
}
void solve()
{
    long long int a, b, c, d, x, y, n, m, k, l, i, j, Max = INT_MIN, Min = INT_MAX, ctr = 0, cnt = 0, ans = 0, lo, hi, mid, q;
    char ch;
    cin >> n;
    adj.clear();

    adj = vector<vector<long long int>>(n + 1);
    pair<long long int, long long int> p = {0, 0};
    par = vector<vector<pair<long long int, long long int>>>(n + 1, vector<pair<long long int, long long int>>(21, p));
    depth = vector<long long int>(n + 1, 0);
    v[0] = 1;
    for (i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0, 0);

    cin >> q;
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        cout << find_lca(a, b) << endl;
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, T;

    T = 1;
    cin >> T;

    for (i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}