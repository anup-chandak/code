/*







#include <iostream>
Description
Given a string S, find the longest string T such that:
→ T is the prefix of S.
→ T is the suffix of S.
→ T is present in the middle of S, such that T is not a prefix and suffix.

Suppose S = “aaaa”, then T = “aa”.
aa is a prefix, S[0..1].
aa is a suffix S[2..3].
aa is present in the middle and it is not a prefix or suffix, S[1..2].

If no T exists then print -1.

 

Input Format
The first line contains an integer T, ( 1 ≤ T ≤ 10000) - the number of test cases.

The first line of each test case contains an integer N, ( 2 ≤ N ≤ 100000).

The second line contains a string S of length N.

Sum of N across all test cases ≤ 10^6.

Output Format
For each test case print the string T, if no string T exists print -1.

Constraints
Sample Input 1
3
9
abababaab
6
ffffff
5
abcde
Sample Output 1
ab
ffff
-1 */
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the Z-array
vector<int> calculate_z_array(string s)
{
    int n = s.length();
    vector<int> z(n, 0);
    z[0] = n;  // Z[0] is the length of the entire string
    int l = 0, r = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(i <= r) 
            z[i] = min(r - i + 1, z[i - l]);
        
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        
        if(i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Calculate the Z-array for the string
        vector<int> z = calculate_z_array(s);

        // Store the length of the longest prefix-suffix that appears in the middle
        int longest_prefix_suffix = -1;

        // Iterate over all possible prefix-suffix lengths
        for(int i = 1; i < n; i++) {
            // Check if the substring from the i-th position is a suffix (i.e., z[i] == n - i)
            if(z[i] == n - i) {
                // Check if this length appears anywhere in the middle (not just as a prefix or suffix)
                for(int j = 1; j < i; j++) {
                    if(z[j] >= n - i) {
                        longest_prefix_suffix = n - i;
                        break;
                    }
                }
                if(longest_prefix_suffix != -1) break;
            }
        }

        if(longest_prefix_suffix == -1) {
            cout << "-1" << endl;
        } else {
            cout << s.substr(0, longest_prefix_suffix) << endl;
        }
    }
    return 0;
}