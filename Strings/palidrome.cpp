/*


Description
Given a string of length 
n
n, your task is to determine the longest palindromic substring of the string. For example, the longest palindrome in "algoazzaa" is "azza". If there are multiple longest palindromic substrings, Output the one which comes first in the string.

Input Format
The first line contains 
T
T - the number of test cases.
The first line of each test case contains a string of length 
n
n. Each character is one of a–z.

Output Format
For each test case, Output the Longest Palindromic Substring.
If there are multiple longest palindromic substrings, Output the one which comes first in the string.

Constraints
1
≤
T
≤
1
0
4
1≤T≤10 
4
 
1
≤
n
≤
1
0
5
1≤n≤10 
5
 


Sum of 
n
n across all test cases is 
≤
≤ 
1
0
6
10 
6
 .

Sample Input 1
9
algoazzaa
aaaaaaaaaa
ababababab
ihpohpzoffel
flexflexvpqxierullgcfckjqflexflex
obsession
abcxcbaxcba
zzabc
aaccaabbaaccaaccaabbaaccaa
Sample Output 1
azza
aaaaaaaaaa
ababababa
ff
cfc
ses
abcxcba
zz
aaccaabbaaccaaccaabbaaccaa

*/

#include <iostream>

// Write your code here

// you can set your Template at profile settings [https://maang.in/profile/template-code]
      #include <iostream>
#include <vector>
#include <string>

using namespace std;

string preprocess(string s) {
    if (s.empty()) return "^$";
    string ret = "^";
    for (int i = 0; i < s.length(); i++){
        ret += "#" + s.substr(i, 1);
    } 
    ret += "#$";
    return ret;
}

string longestPalindrome(string s) {
    string T = preprocess(s);
    int n = T.length();
    vector<int> P(n);
    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++) {
        int i_mirror = 2*C - i;
        if (R > i) {
            P[i] = min(R-i, P[i_mirror]);
        } else {
            P[i] = 0;
        }
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n-1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout << longestPalindrome(s) << endl;
    }
    
    return 0;
}
