/*

Description
You have given an undirected graph G with N nodes and M edges. You've to answer Q queries. Each query is either of the following two types:

1 X: Print the size of the connected components containing node X.
2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected component, else print ‘NO’ (without quotes).
Input Format
The first line of input contains three space-separated integers N, M, and Q (1 ≤ N, M, Q ≤ 105).
Next M lines contain two space-separated integers u and v (1 ≤ u, v ≤ N).
Each of the next Q lines contains queries of one of the types as described in the statement.

Output Format
Print Q lines as the answer to the Q queries, each on a new line.

Constraints
Sample Input 1
6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6
Sample Output 1
3
1
NO
2
YES


*/





#include <iostream>

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100001;
vector<int> graph[MAXN];  // Graph represented as adjacency lists
int visited[MAXN];        // Visited array to store component color for each node
int sizeCC[MAXN];         // Array to store size of each connected component
int N, M, Q;
int color = 1;            // Color/ID for connected components

// Function to perform DFS and mark all connected nodes with the same component color
void dfs(int node, int color) {
    visited[node] = color;
    sizeCC[color]++;
    for (int neigh : graph[node]) {
        if (visited[neigh] == 0) {
            dfs(neigh, color);
        }
    }
}

int main() {
    // Input: N = number of nodes, M = number of edges, Q = number of queries
    cin >> N >> M >> Q;

    // Reading the edges
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // Reading the queries
    vector<vector<int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            queries[i] = {t, x};
        } else {
            int x, y;
            cin >> x >> y;
            queries[i] = {t, x, y};
        }
    }

    // Finding all connected components using DFS
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {  // If the node hasn't been visited
            dfs(i, color);
            color++;
        }
    }

    // Processing the queries
    for (const auto& query : queries) {
        if (query[0] == 1) {
            int x = query[1];
            cout << sizeCC[visited[x]] << endl;
        } else {
            int x = query[1], y = query[2];
            if (visited[x] == visited[y]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}    