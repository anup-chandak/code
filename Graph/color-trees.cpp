/*


Description
You have been given a tree with N nodes and N - 1 edges. You want to colour each node, such that no two adjacent nodes (directly connected by an edge) and no two nearly-adjacent nodes (both directly connected to a common node with edges) has the same colour. 
Your task is to find the minimum number of colours required to accomplished this. 

Input Format
The first line of input contains N. Each of the remaining N−1 lines describes an edge in terms of the two nodes it connects.

Output Format
Print the minimum number of colours require.

Constraints
1 ≤ N ≤ 105

Sample Input 1
4
1 2
4 3
2 3
Sample Output 1
3
Note
We require 4 different colours, colour(1) = 1, colour(2) = 2, colour(3) = 3, colour(4) = 1.

*/




#include <iostream>

// Write your code here
// You can set your Template at profile settings [https://maang.in/profile/template-code]

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int> deg(n+1, 0);
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        deg[x]++; deg[y]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(deg[i]>ans){
            ans=deg[i];
        }
    }
    cout<<ans+1<<"\n";
}
