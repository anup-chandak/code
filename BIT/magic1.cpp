/*

Description
You are given a string, 
d
o
c
s
t
r
i
n
g
docstring, representing a line of documentation for a programming language:

Function and variable names, as well as constants, are enclosed in backticks (`).
Each quoted sentence can contain several items (functions, variables, and constants) separated by space.
Function and variable names are written in snake case. Snake case means that after the first word in the name, additional words are separated by an underscore _. Each word consists only of lowercase English letters.
Constants are written in upper case. Upper case format is the same as snake case except that each word consists only of uppercase English letters.
Your task is to convert all function and variable names in the 
d
o
c
s
t
r
i
n
g
docstring from snake case to camel case. Constants should not be changed.

In camel case format, there are no spaces, underscores, or characters separating words. Instead, the first letter of every word is capitalized, except for the very first word.

Input Format
The input consists of multiple test cases.
The first line contains a single integer 
T
T, the number of test cases.

Each test case consists of a single line containing the 
d
o
c
s
t
r
i
n
g
docstring, a string of length up to 2000 characters.

Output Format
For each test case, output the converted camel case version of the 
d
o
c
s
t
r
i
n
g
docstring.

Constraints
1
≤
T
≤
100
1≤T≤100

Each word in the 
d
o
c
s
t
r
i
n
g
docstring has a maximum length of 100.

Sample Input 1
2 
`example_function` is the `first_example` 
`CONSTANT_NAME` and `sample_test_case`  
Sample Output 1
exampleFunction is the firstExample 
CONSTANT_NAME and sampleTestCase  
Sample Input 2
3 
this is a `simple_case` test 
`HELLO_WORLD` remains unchanged 
convert `long_example_case` properly  
Sample Output 2
this is a simpleCase test
HELLO_WORLD remains unchanged 
convert longExampleCase properly  
Note
In Sample Input 1, example_function is converted to exampleFunction by removing underscores and capitalizing each word after the first. CONSTANT_NAME remains the same as it is a constant in uppercase.
In Sample Input 2, each snake case variable is transformed to camel case. Constants like HELLO_WORLD remain unchanged.



*/


/*

Description
A state with n flags of ON or OFF can be represented by a sequence of bits where 0,1,...,n−1 -th flag corresponds to 1 (ON) or 0 (OFF). The state can be managed by the corresponding decimal integer because the sequence of bits is a binary representation where each bit is 0 or 1.

Given a sequence of bits with 60 flags that represent a state, perform the following operations. Note that each flag of the bits is initialized by OFF.

test(i): Print 1 if ith flag is ON, otherwise 0.
set(i): Set ith flag to ON
clear(i): Set ith flag to OFF
flip(i): Inverse ith flag
all: Print 1 if all flags are ON, otherwise 0
any: Print 1 if at least one flag is ON, otherwise 0
none: Print 1 if all flags are OFF, otherwise 0
count: Print the number of ON flags
val: Print the decimal value of the state
Input Format
The input is given in the following format.

q
query1
query2
:
queryq
Each query queryj is given in the following format: either only t  or  t  i  , where t is the query type.

The first digit t = 1, 2, 3 ,...,8, 9 represents the operation test(i), set(i), clear(i), flip(i), all, any, none, count or val respectively.

Output Format
Print the result in a line for each test, all, any, none, count and val operation.

Constraints
1 ≤ q ≤ 200,000
0 ≤ i < 60
Sample Input 1
14
2 0
2 1
2 2
3 1
1 0
1 1
1 2
1 3
4 3
5
6
7
8
9
Sample Output 1
1
0
1
0
0
1
0
3
13


*/

#include <iostream>

#include<bits/stdc++.h>
 
 
using namespace std;
 
#define ll long long int
 
const int M = 1e9 + 7; 
const int N = 1e7 + 1;
 
 
void solve()
{
    ll x = 0;
    
    ll q, y, j;
    cin >> q;
    
    for(ll i = 0; i < q ; i++)
    {
        cin >> y;
        
        if(y == 1)
        {
            cin >> j;
            if(x & (1LL << j)) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(y == 2)
        {
            cin >> j;
            x |= (1LL << j);
        }
        else if(y == 3)
        {
            cin >> j;
            x  &= (~(1LL << j));
        }
        else if(y == 4)
        {
            cin >> j;
            x ^= (1LL << j);
        }
        else if(y == 5)
        {
            
            if(__builtin_popcountll(x) == 60)
                cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(y == 6)
        {
            if(__builtin_popcountll(x) > 0)
                cout << 1 << endl;
            else cout << 0 << endl;
            
        }
        else if(y == 7)
        {
            if(__builtin_popcountll(x) == 0)
                cout << 1 << endl;
            else cout << 0 << endl;
            
        }
        else if(y == 8)
        {
            cout << __builtin_popcountll(x) << endl;
        }
        else if(y == 9)
        {
            cout << x << endl;
        }
        
    }
        
    
    
}
signed main()
{
    ll t;
    //cin >> t;
    t = 1;
    while(t--)solve();
}


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void solve() {
    int q;
    cin >> q;
    ll val = 0;
    while (q--) {
        int t, i;
        cin >> t;
        //t++;
        if (t == 1) {
            cin >> i;
            cout << ((val >> i) & 1) << endl;
        }
        if (t == 2) {
            cin >> i;
            val |= (1LL << i);
        }
        if (t == 3) {
            cin >> i;
            val &= (~(1LL << i));
        }
        if (t == 4) {
            cin >> i;
            val ^= (1LL << i);
        }
        if (t == 5) {
            if (__builtin_popcountll(val) == 60) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 6) {
            if (__builtin_popcountll(val) >= 1) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 7) {
            if (__builtin_popcountll(val) == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 8) {
            cout << __builtin_popcountll(val) << endl;
        }
        if (t == 9) {
            cout << val << endl;
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);


    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}


// Write your code here
// You can set your Template at profile settings [https://maang.in/profile/template-code]
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void solve() {
    int q;
    cin >> q;
    ll val = 0;
    while (q--) {
        int t, i;
        cin >> t;
        //t++;
        if (t == 1) {
            cin >> i;
            cout << ((val >> i) & 1) << endl;
        }
        if (t == 2) {
            cin >> i;
            val |= (1LL << i);
        }
        if (t == 3) {
            cin >> i;
            val &= (~(1LL << i));
        }
        if (t == 4) {
            cin >> i;
            val ^= (1LL << i);
        }
        if (t == 5) {
            if (__builtin_popcountll(val) == 60) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 6) {
            if (__builtin_popcountll(val) >= 1) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 7) {
            if (__builtin_popcountll(val) == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        if (t == 8) {
            cout << __builtin_popcountll(val) << endl;
        }
        if (t == 9) {
            cout << val << endl;
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);


    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}