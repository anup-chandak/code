/*

Description
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n × m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input Format
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either ‘.’ (floor) or '#' (wall).

Output Format
Print one integer: the number of rooms.

Constraints
1 ≤ n, m ≤ 1000

Sample Input 1
5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 1
3


*/




#include <iostream>

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> graph;
vector<vector<int>> visited;
int n, m;
vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool check(int row, int col) {

    return row >= 0 && row < n && col >= 0 && col < m && graph[row][col] == '.';
}

void dfs(int row, int col) {

    visited[row][col] = 1;
    for(auto direction : directions) {

        int newRow = row + direction[0];
        int newColumn = col + direction[1];

        if(check(newRow, newColumn) && !visited[newRow][newColumn]) {
            dfs(newRow, newColumn);
        }
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    graph = vector<vector<char>>(n + 1, vector<char>(m + 1));
    visited = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            cin >> graph[i][j];
        }
    }

    int rooms = 0;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            if(!visited[i][j] && graph[i][j] == '.') {

                rooms++;
                dfs(i, j);
            }
        }
    }

    cout << rooms << endl;

    return 0;
}
