/*


Description
There are n cities and m roads. The capital is located at 1. Your task is to determine the length of the shortest route from the capital to every city.

Input Format
The first input line has two integers n and m: the number of cities and road connections. The cities are numbered 1, 2, …, n, and city 1 is Capital.
After that, there are m lines describing the roads. Each line has three integers a, b and c: a road begins at city a, ends at city b, and its length is c. Each road is a one-way road.
You can assume that it is possible to travel from Capital to all other cities.

Output Format
Print n integers: the shortest route lengths from Capital to cities 1, 2, …, n.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n
1 ≤ c ≤ 109

Sample Input 1
3 4
1 2 6
1 3 2
3 2 3
1 3 4
Sample Output 1
0 5 2

*/




#include <iostream>

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using lli = long long;
using state = pair<lli, lli>;

lli n,m;
vector<vector<state>> g;
lli dis[100010];
lli vis[100010];

class prioritize{
	public:
		bool operator() (state& s1, state& s2){
			return s1.S > s2.S;
		}
};

void dijkstra(lli src){
	for(int i=1;i<=n;i++){
		dis[i] = 1e18;
		vis[i] = 0;
	}
	priority_queue<state, vector<state>, prioritize> pq;
	dis[src] = 0;
	pq.push(make_pair(src, dis[src]));
	while(!pq.empty()){
		state small_dis_node = pq.top();
		pq.pop();
		if(vis[small_dis_node.F]) continue;
		vis[small_dis_node.F] = 1;
		for(auto v: g[small_dis_node.F]){
			lli neigh = v.F;
			lli weight = v.S;
			if(dis[neigh] > dis[small_dis_node.F] + weight){
				dis[neigh] = dis[small_dis_node.F] + weight;
				pq.push(make_pair(neigh, dis[neigh]));
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(lli i=0;i<m;i++){
		lli a,b,c;
		cin>>a>>b>>c;
		g[a].emplace_back(make_pair(b,c));
	}
	dijkstra(1);
	for(lli i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve();
	return 0;
}