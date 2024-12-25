/*

Description
You have given an undirected graph of N vertices and M edges. Edge weight d on edge between nodes u and v represents that u and v are connected by a thread of length d units. 
You set node A on to the fire. It takes to fire 1 unit of time to travel 1 unit of distance via threads.
Let T be the minimum time in which all the threads will be burned out. 

Your task is to find 10T. We can prove that 10T will always be an integer number.

See the sample test cases for more explanation.

Input Format
The first line of input contains N - the number of nodes in the graph.
The second line contains M - the number of edges in the graph.
Next M lines contain three integers u, v, d - there is a thread between node u and v of length d.
The last line of input contains A - the node on which we set fire.

It’s guaranteed that graph is connected.

Output Format
Print the value of 10T.

Constraints
1 ≤ N ≤ 2 x 105
1 ≤ M ≤ 2 x 105
1 ≤ u, v ≤ N
1 ≤ d ≤ 109

Sample Input 1
2
1
1 2 2
1
Sample Output 1
20
Sample Input 2
3
3
1 2 2
2 3 2
1 3 6
1
Sample Output 2
50
Sample Input 3
3
3
1 2 2
1 3 2
2 3 1
1
Sample Output 3
25
Note
Explanation 1:

At t = 0, node 1 is at fire.
At t = 1, thread 1-2 is half burned.
At t = 2, thread 1-2 is fully burned.
So T = 2. And 10T = 20.

Explanation 2:

At t = 0, node 1 is at fire.
At t = 2, thread 1-2 is fully burned, and thread 1-3 is 1/3rd burned.
At t = 4, threads 1-2 and 2-3 are fully burned, and 4 units of thread 1-3 are burned. For the remaining 2 units of thread 1-3, fire is approaching from both ends.
At t = 5, all threads are fully burned.
So T = 5. And 10T = 50.

Explanation 3:

At t = 0, node 1 is starting to burn.
At t = 2, threads 1-2 and 1-3 are fully burned. Now for thread 2-3, fire is approaching from both ends at equal speed.
At t = 2.5, thread 2-3 is fully burned.
So T = 2.5. And 10T = 25.


*/




#include <iostream>

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using lli = long long;
using state = pair<lli, lli>;

lli n, m;

vector<vector<state>> g;
vector<pair<state, lli>> edges;
vector<lli> dis;

class prioritize{
	public:
		bool operator() (state& p1, state& p2){
			return p1.S > p2.S;
		}

};

void dijkstra(lli src){
	priority_queue<state, vector<state>, prioritize> pq;
	dis[src] = 0;
	pq.push(make_pair(src, dis[src]));
	while(!pq.empty()){
		state small_dis_node = pq.top();
		pq.pop();
		for(auto v: g[small_dis_node.F]){
			int neigh = v.F;
			int weight = v.S;
			if(dis[neigh] > dis[small_dis_node.F] + weight){
				dis[neigh] = dis[small_dis_node.F] + weight;
				pq.push(make_pair(v.F, dis[neigh]));
			}
		}
	}
}


void solve(){
	cin>>n>>m;
	g.resize(n+1);
	dis.assign(n+1, 1e18);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].emplace_back(make_pair(b, c));
		g[b].emplace_back(make_pair(a, c));
		edges.emplace_back(make_pair(make_pair(a, b), c));
	}
	lli start;
	cin>>start;
	dijkstra(start);
	lli ans = -1;
	for(auto v: edges){
		lli edge_a = v.F.F;
		lli edge_b = v.F.S;
		lli edge_weight = v.S;
		ans = max(ans, (dis[edge_a]+dis[edge_b]+edge_weight)*5);
	}
	cout<<ans<<"\n";

}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve();
	return 0;
}