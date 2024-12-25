/*


Description
You have given an undirected graph with n nodes, and m edges between them. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.

Input Format
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line has two integers a and b: there is an edge between those nodes.
An edge always connects two different nodes, and there is at most one edge between any two nodes.

Output Format
Print the number of ways to add such edge, described in the statement.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5 4
1 2
2 3
1 3
4 5
Sample Output 1
6
Sample Input 2
4 3
1 2
2 3
3 4
Sample Output 2
0
Note
Explanation 1:
There are 6 ways to add edge so that the number of connected components in the graph decreases: (1, 4), (1, 5), (2, 4), (2, 5), (3, 4), (3, 5).

Explanation 2:
The given graph is already connected. Even if add any edge, we can't decrease the number of connected components.

*/




#include <iostream>

// Write your code here
// You can set your Template at profile settings [https://maang.in/profile/template-code]

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int comp_no, vector<int>& vis, vector<int>& comp, vector<vector<int>>& g) {
    vis[node] = comp_no;
    comp[comp_no] += 1;
    for (int v : g[node]) {
        if (!vis[v]) {
            dfs(v, comp_no, vis, comp, g);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int comp_no = 0;
    vector<int> comp(n + 1, 0);     // Component sizes
    vector<int> vis(n + 1, 0);      // Visited nodes
    vector<vector<int>> g(n + 1);   // Graph adjacency list

    // Read edges
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // Depth-first search to label components
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            comp_no += 1;
            dfs(i, comp_no, vis, comp, g);
        }
    }

    // Calculate the result
    long long sumcomp = 0, sumele = 0;
    for (int i = 1; i <= comp_no; ++i) {
        sumcomp += comp[i];
        sumele += static_cast<long long>(comp[i]) * comp[i];
    }
    cout << (sumcomp * sumcomp - sumele) / 2 << endl;

    return 0;
}