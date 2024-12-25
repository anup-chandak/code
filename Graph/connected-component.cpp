/*


Description
You have a 2-D array of size N x M. Consider connected 0s (which share a common edge) as one single component and 1s as walls. Replace 0s with the size of the connected component but if the size of the component is one, then leave it with 0.

Input Format
The first line contains a single integer t, the number of test cases.
For each test case, the first line contains two integers N and M and then there are N lines containing M 0s and 1s, representing a N x M binary matrix.

Output Format
For each test case, print the final matrix after replacing all the 0s accordingly.

Constraints
1 ≤ Sum of (N x M) over all test cases ≤ 2 x 105
0 ≤ Ai ≤ 1

Sample Input 1
2
2 2
0 1
1 0
6 5
1 0 0 1 0
0 1 0 0 0
0 0 1 1 0
0 1 1 0 1
1 1 1 1 1
0 1 0 0 0
Sample Output 1
0 1 
1 0 
1 7 7 1 7
4 1 7 7 7
4 4 1 1 7
4 1 1 0 1
1 1 1 1 1
0 1 3 3 3
Note
In the first test case, we have only 2 components and both have size 1. So nothing is replaced.
In the second test case, we have a total of 5 components of size 7, 4, 3, 1, 1 respectively. So all the 0s are replaced accordingly.



*/




#include <iostream>

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
#define F first
#define S second
#define int long long int 

int n,m;
vector<vector<int>> g;
using state = pair<int,int>;
vector<vector<int>> vis;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

bool check(int x, int y)
{
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}

void bfs(int i, int j, int num_comp)
{

    queue<state> q;
    vis[i][j]=num_comp;
    q.push({i,j});

    while(!q.empty())
    {
        state node = q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            int ii = node.F + dx[k];
            int jj = node.S + dy[k];

            if(check(ii,jj) && vis[ii][jj]==0 && g[ii][jj]!=1)
            {
                vis[ii][jj]=num_comp;
                q.push({ii,jj});
            }
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int  t;
    cin>>t;
    while(t--)
    {   
        g.clear();
        vis.clear();

        cin>>n>>m;
        g.resize(n);
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {   
            g[i].resize(m);
            for(int j=0;j<m;j++)
            {
                cin>>g[i][j];
            }
        }

        int num_comp = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]!=1 && vis[i][j]==0)
                {
                    num_comp++;
                    bfs(i,j,num_comp);
                }
            }
        }

        vector<vector<state>> components;
        components.clear();

        components.resize(n*m + 1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                components[vis[i][j]].push_back({i,j});
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]!=1 && components[vis[i][j]].size()!=1) g[i][j] = components[vis[i][j]].size();
                cout<<g[i][j]<<" ";
            }
            cout<<'\n';
        }

    }
    return 0;
}
