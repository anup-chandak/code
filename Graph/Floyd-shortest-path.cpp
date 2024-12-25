/*

Description
There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.

Input Format
The first input line has three integers n, m and q: the number of cities, roads, and queries.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose length is c. All roads are two-way roads.
Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route between cities a and b.

Output Format
Print the length of the shortest route for each query. If there is no route, print −1 instead.

Constraints
1 ≤ n ≤ 500
1 ≤ m ≤ n2
1 ≤ q ≤ 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109

Sample Input 1
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
Sample Output 1
5
5
8
-1
3
Sample Input 2
2 2 1
1 2 1
1 2 2
1 2
Sample Output 2
1


*/




#include <iostream>

#include<bits/stdc++.h>
using namespace std;

#define int long long
int  INF =1e15;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     int n,m,q;
     cin>>n>>m>>q;

     vector<vector<int>>dis(n+1,vector<int>(n+1,INF));
   
     for(int i=1;i<=m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            dis[a][b]=min(dis[a][b],c);
            dis[b][a]=min(dis[b][a],c);
     }

     for(int i=1;i<=n;i++) dis[i][i]=0;

     for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
     }
     while(q--){
        int x,y;
        cin>>x>>y;

        int ans=dis[x][y];
        if(ans==INF)cout<<-1<<"\n";
        else cout<<ans<<"\n";
     }
    return 0;
}