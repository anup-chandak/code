/*

Description
Consider a competition that uses a point system to determine the team rankings. After a match, the winning team receives 3 points, the losing team receives 0 points, or, if tied, both teams receive 1 point.

The team that accumulates the most points wins the competition. However, if there is a tie, the team with the highest goal difference among the tied teams is the winner. Goal difference is calculated as:

goal difference
=
scored
−
conceded
goal difference=scored−conceded
You are given 4 arrays of the same length: 
w
i
n
s
wins, 
d
r
a
w
s
draws, 
s
c
o
r
e
d
scored, and 
c
o
n
c
e
d
e
d
conceded. Within each array, the 
i
t
h
i 
th
  element represents the corresponding metric for the 
i
t
h
i 
th
  team – i.e., scored goals 
s
c
o
r
e
d
[
i
]
scored[i], conceded goals 
c
o
n
c
e
d
e
d
[
i
]
conceded[i], matches won 
w
i
n
s
[
i
]
wins[i], and matches tied 
d
r
a
w
s
[
i
]
draws[i] during the competition (for each 
i
i in 
0
,
1
,
…
,
wins.length - 1
0,1,…,wins.length - 1).

Your task is to determine the indices of the winning team and the team in second place. Return an array of exactly two integers, where the first is the index of the winning team and the second is the index of the team in second place.

It is guaranteed that there will only be one winning team and one team in second place.

Input Format
The input consists of multiple test cases.
The first line contains a single integer 
T
T, the number of test cases.
For each test case:
The first line contains an integer 
n
n, the number of teams.
The second line contains 
n
n space-separated integers representing 
w
i
n
s
wins.
The third line contains 
n
n space-separated integers representing 
d
r
a
w
s
draws.
The fourth line contains 
n
n space-separated integers representing 
s
c
o
r
e
d
scored goals.
The fifth line contains 
n
n space-separated integers representing 
c
o
n
c
e
d
e
d
conceded goals.

Output Format
For each test case, output an array of two integers – the index of the winning team followed by the index of the team in second place.

Constraints
1
≤
T
≤
100
1≤T≤100

2
≤
n
≤
100
2≤n≤100

0
≤
w
i
n
s
[
i
]
,
d
r
a
w
s
[
i
]
≤
100
0≤wins[i],draws[i]≤100

0
≤
s
c
o
r
e
d
[
i
]
,
c
o
n
c
e
d
e
d
[
i
]
≤
1000
0≤scored[i],conceded[i]≤1000

Sample Input 1
1  
3  
2 1 0  
1 5 6  
20 15 10  
20 10 15  
Sample Output 1
1 0  
Sample Input 2
1  
4  
3 1 2 2  
1 5 4 4  
30 10 20 40  
32 13 18 37  
Sample Output 2
3 2  
Note
In Sample Input 1:
The team with index 
0
0 received 
2
×
3
+
1
=
7
2×3+1=7 points.
The team with index 
1
1 received 
1
×
3
+
5
=
8
1×3+5=8 points.
The team with index 
2
2 received 
0
×
3
+
6
=
6
0×3+6=6 points.
Since 
8
>
7
>
6
8>7>6, the team with index 
1
1 is the winner, and the team with index 
0
0 is in second place. Thus, the answer is 
[
1
,
0
]
[1,0].

In Sample Input 2:
The team with index 
0
0 received 
3
×
3
+
1
=
10
3×3+1=10 points.
The team with index 
3
3 received 
2
×
3
+
4
=
10
2×3+4=10 points.
Three teams are tied with the highest number of points: teams with indices 
0
0, 
2
2, and 
3
3.
The team with index 
0
0 has a goal difference of 
30
−
32
=
−
2
30−32=−2.
The team with index 
2
2 has a goal difference of 
20
−
18
=
2
20−18=2.
The team with index 
3
3 has a goal difference of 
40
−
37
=
3
40−37=3.
Since 
3
>
2
>
−
2
3>2>−2, the team with index 
3
3 is the winner, and the team with index 
2
2 is in second place. So, the answer is 
[
3
,
2
]
[3,2].


*/


#include <iostream>

#include <bits/stdc++.h>
using namespace std;

pair<int, int> findTopTeams(const vector<int>& wins, const vector<int>& draws, const vector<int>& scored, const vector<int>& conceded) {
    int n = wins.size();
    vector<pair<int, int>> pointsAndGoalDiff(n);
    
    // Calculate points and goal difference
    for (int i = 0; i < n; i++) {
        int points = 3 * wins[i] + draws[i];
        int goalDiff = scored[i] - conceded[i];
        pointsAndGoalDiff[i] = {points, goalDiff};
    }
    
    vector<int> sortedIndices(n);
    iota(sortedIndices.begin(), sortedIndices.end(), 0);
    
    // Sort by points, then by goal difference in descending order
    sort(sortedIndices.begin(), sortedIndices.end(), [&](int a, int b) {
        return pointsAndGoalDiff[a] > pointsAndGoalDiff[b];
    });

    return {sortedIndices[0], sortedIndices[1]};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> wins(n), draws(n), scored(n), conceded(n);

        for (int i = 0; i < n; i++) cin >> wins[i];
        for (int i = 0; i < n; i++) cin >> draws[i];
        for (int i = 0; i < n; i++) cin >> scored[i];
        for (int i = 0; i < n; i++) cin >> conceded[i];

        auto result = findTopTeams(wins, draws, scored, conceded);
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}

