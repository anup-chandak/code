/*


You are monitoring the building density in a district of houses. The district is represented as a number line, where a house can be built at each numbered point on the line if at least one of the neighboring points is not occupied. Initially, there are no houses in the district.

You are given 
q
u
e
r
i
e
s
queries, an array of integers representing the locations of new houses in the order in which they will be built. After each house is built, your task is to find the longest segment of contiguous houses in the district.

Return an array of integers representing the longest segment of contiguous houses after each respective house from 
q
u
e
r
i
e
s
queries is built.

Note: It's guaranteed that all of the house locations in 
q
u
e
r
i
e
s
queries are unique and no house was built at a point with existing houses on both left and right adjacent points.

Assume that array indices are 
0
0-based.

Input Format
The first line contains an integer 
n
n, the number of house locations.
The second line contains 
n
n space-separated integers representing 
q
u
e
r
i
e
s
queries.

Output Format
Output an array of integers representing the longest segment of contiguous houses after each respective house from 
q
u
e
r
i
e
s
queries is built.

Constraints
1
≤
n
≤
100
1≤n≤100

0
≤
q
u
e
r
i
e
s
[
i
]
≤
1
0
5
0≤queries[i]≤10 
5
 

Sample Input 1
3  
2 1 3  
Sample Output 1
1 2 3  
Sample Input 2
4  
1 3 0 4  
Sample Output 2
1 1 2 2  
Note
In Sample Input 1:
After 
q
u
e
r
i
e
s
[
0
]
=
2
queries[0]=2, there is only one house in the district (at 
2
2), so the answer is 
1
1. After 
q
u
e
r
i
e
s
[
1
]
=
1
queries[1]=1, there are two houses in the district (at 
1
1 and 
2
2). These two houses form a contiguous segment, so the answer is 
2
2. After 
q
u
e
r
i
e
s
[
2
]
=
3
queries[2]=3, there are three houses in the district (at 
1
1, 
2
2, and 
3
3), forming a contiguous segment, so the answer is 
3
3. Thus, the final output is 
[
1
,
2
,
3
]
[1,2,3].
In Sample Input 2:
After 
q
u
e
r
i
e
s
[
0
]
=
1
queries[0]=1, there is one house at 
1
1, so the answer is 
1
1. After 
q
u
e
r
i
e
s
[
1
]
=
3
queries[1]=3, there are houses at 
1
1 and 
3
3, which are not contiguous, so the answer is still 
1
1. After 
q
u
e
r
i
e
s
[
2
]
=
0
queries[2]=0, there are houses at 
0
0, 
1
1, and 
3
3. This forms a segment of 
2
2 contiguous houses at 
0
0 and 
1
1, so the answer is 
2
2. After 
q
u
e
r
i
e
s
[
3
]
=
4
queries[3]=4, there are two segments of 
2
2 contiguous houses, so the answer is still 
2
2.
Thus, the final output is 
[
1
,
1
,
2
,
2
]
[1,1,2,2].

*/


#include <iostream>

#include <bits/stdc++.h>
using namespace std;

vector<int> longestSegmentAfterQueries(const vector<int>& queries) {
    set<int> builtHouses;
    map<int, int> segmentLengths;  // Tracks segment lengths and their counts
    vector<int> results;
    int maxSegment = 0;

    for (int pos : queries) {
        // Insert the position
        auto it = builtHouses.insert(pos).first;

        int left = pos - 1;
        int right = pos + 1;

        // Calculate the length of the new segment
        int leftSegment = (builtHouses.count(left) ? segmentLengths[left] : 0);
        int rightSegment = (builtHouses.count(right) ? segmentLengths[right] : 0);
        int newSegment = leftSegment + 1 + rightSegment;

        // Update max segment length
        maxSegment = max(maxSegment, newSegment);
        results.push_back(maxSegment);

        // Update segment lengths
        segmentLengths[pos - leftSegment] = newSegment;
        segmentLengths[pos + rightSegment] = newSegment;
    }
    return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> queries(n);
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    vector<int> result = longestSegmentAfterQueries(queries);
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
