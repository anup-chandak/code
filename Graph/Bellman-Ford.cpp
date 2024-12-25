/*


Description
You have given a graph G with n nodes and m edges. Each edge has an integer weight associated with. The weight of an edge may negative, positive or zero. If the graph contains a cycle with total weight > 0, print -1. Otherwise, find the weight of the highest weighted path from node 1 to n.

Input Format
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
Then, there are m lines describing the edges. Each line has three integers a, b and x: the edge starts at node a, ends at node b, and weight of the edge is x. All edges are unidirectional edges.
You can assume that it is possible to get from node 1 to node n.

Output Format
Print the answer on a new line.

Constraints
1 ≤ 2500 ≤ n
1 ≤ 5000 ≤ m
1 ≤ a, b ≤ n
−109 ≤ x ≤ 109

Sample Input 1
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
Sample Output 1
5

*/




#include <iostream>

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using lli = long long int;
using state = pair<lli,lli>;


lli n, m;
vector<vector<lli>> edges;
vector<lli> dis;
bool negative_cycle = false;



void Solve(){
	cin>>n>>m;
	dis.assign(n+1, 1e18);
	for(lli i=0;i<m;i++){
		lli a, b, c;
		cin>>a>>b>>c;
		vector<lli> temp;
		temp.emplace_back(a);
		temp.emplace_back(b);
		temp.emplace_back(-c);
		edges.emplace_back(temp);
	}
	lli max_distance = -1;
	dis[1] = 0;
	for(lli i=1;i<=n-1;i++){
		for(auto e: edges){
			lli u = e[0];
			lli v = e[1];
			lli w = e[2];
			dis[v] = min(dis[v], dis[u] + w);
		}
	}
	for(auto e: edges){
		lli u = e[0];
		lli v = e[1];
		lli w = e[2];
		if(dis[v] > dis[u] + w){
			negative_cycle = true;
			break;
		}
	}
	if(negative_cycle){
		cout<<-1<<"\n";
	}else{
		cout<<-dis[n]<<"\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	Solve();
	return 0;
}
