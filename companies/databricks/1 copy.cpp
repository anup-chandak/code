/*

Description
Given an array of integers 
t
a
r
g
e
t
target, return an array 
r
e
s
u
l
t
result consisting of all elements 
t
a
r
g
e
t
[
i
]
target[i] that are greater than both of their neighbors, i.e., elements that satisfy the condition:

t
a
r
g
e
t
[
i
]
>
max
⁡
(
t
a
r
g
e
t
[
i
−
1
]
,
t
a
r
g
e
t
[
i
+
1
]
)
target[i]>max(target[i−1],target[i+1])
Note: The first and the last elements, are included by default in the 
r
e
s
u
l
t
result array because they do not have two neighbors.

Input Format
The input consists of multiple test cases.
The first line contains a single integer 
T
T, the number of test cases.
For each test case:
The first line contains an integer 
n
n, the length of the array.
The second line contains 
n
n space-separated integers representing the elements of 
t
a
r
g
e
t
target.

Output Format
For each test case, output the 
r
e
s
u
l
t
result array for the corresponding 
t
a
r
g
e
t
target array on a new line.

Constraints
1
≤
T
≤
100
1≤T≤100

1
≤
n
≤
100
1≤n≤100

−
100
≤
t
a
r
g
e
t
[
i
]
≤
100
−100≤target[i]≤100

Sample Input 1
1  
5  
1 3 1 3 2  
Sample Output 1
1 3 3 2  
Sample Input 2
1  
4  
1 3 3 1  
Sample Output 2
1 1  
Note
In Sample Input 1:
t
a
r
g
e
t
[
0
]
target[0] is included in 
r
e
s
u
l
t
result by default because it doesn't have two neighbors. 
r
e
s
u
l
t
=
[
1
]
result=[1].
t
a
r
g
e
t
[
1
]
target[1] is greater than both 
t
a
r
g
e
t
[
0
]
target[0] and 
t
a
r
g
e
t
[
2
]
target[2], so it is included in 
r
e
s
u
l
t
result. 
r
e
s
u
l
t
=
[
1
,
3
]
result=[1,3].
t
a
r
g
e
t
[
2
]
target[2] is not greater than its neighbors, so it is not included in 
r
e
s
u
l
t
result.
t
a
r
g
e
t
[
3
]
target[3] is greater than both 
t
a
r
g
e
t
[
2
]
target[2] and 
t
a
r
g
e
t
[
4
]
target[4], so it is included in 
r
e
s
u
l
t
result. 
r
e
s
u
l
t
=
[
1
,
3
,
3
]
result=[1,3,3].
t
a
r
g
e
t
[
4
]
target[4] is included in 
r
e
s
u
l
t
result by default because it doesn't have two neighbors. 
r
e
s
u
l
t
=
[
1
,
3
,
3
,
2
]
result=[1,3,3,2].
In Sample Input 2:
t
a
r
g
e
t
[
0
]
target[0] and 
t
a
r
g
e
t
[
3
]
target[3] are included in 
r
e
s
u
l
t
result by default.


*/


#include <iostream>

#include <bits/stdc++.h>
using namespace std;

vector<int> findPeaks(const vector<int>& target) {
    vector<int> result;
    int n = target.size();
    
    // Add the first element by default
    result.push_back(target[0]);
    
    // Process middle elements
    for (int i = 1; i < n - 1; i++) {
        if (target[i] > target[i - 1] && target[i] > target[i + 1]) {
            result.push_back(target[i]);
        }
    }
    
    // Add the last element by default
    result.push_back(target[n - 1]);
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        
        vector<int> target(n);
        for (int i = 0; i < n; i++) {
            cin >> target[i];
        }
        
        vector<int> result = findPeaks(target);
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
