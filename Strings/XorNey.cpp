/*

Description
Given are two sequences a={a0,…,aN−1} and b={b0,…,bN−1} of N non-negative integers each.

You will choose an integer k such that 0≤k<N and an integer x not less than 0, to make a new sequence of length N, a′={a′0,…,a′N−1}, as follows:

a′i=a(i+k)modN XOR x
Find all pairs (k,x) such that a′ will be equal to b.

Input Format
First line contains an integer N, 1 ≤ N ≤ 2*10^5.

Second line contains N space-separated integers,  0≤ ai < 2^30.

Third line contains N space-separated integers,  0≤ bi < 2^30.

Output Format
Print all pairs 
(
k
,
x
)
 such that 
a
′
 and 
b
 will be equal, using one line for each pair, in ascending order of 
k
 (ascending order of 
x
 for pairs with the same 
k
).

If there are no such pairs, the output should be empty.

Constraints
1 ≤ N  ≤ 2*10^5.
0 ≤ ai < 2^30.
0 ≤ bi < 2^30.
Sample Input 1
5
1 4 2 3 0
6 7 4 5 0
Sample Output 1
2 4
Sample Input 2
6
0 1 3 7 6 4
1 5 4 6 2 3
Sample Output 2
2 2
5 5
Sample Input 3
2
1 2
0 0
Sample Output 3
Note
For Sample 1,

The array a = 1 4 2 3 0

The array b = 6 7 4 5 0

Convert a such that , a′i=a(i+2)mod5 ^ 4

The converted array : (2 3 0 1 4)

Taking xor with 4 , the array finally becomes :- 6 7 4 5 0

This is the same as array b. Hence only one pair is obtained.


*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> Kmp(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();

    vector<int> kmp(n + m + 1, 0), arr;
    for (int i = 0; i < n; i++)
        arr.push_back(a[i]);
    arr.push_back(-1);
    for (int i = 0; i < m; i++)
        arr.push_back(b[i]);

    int z = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        z = kmp[i - 1];

        while (z > 0 && arr[z] != arr[i])
        {
            z = kmp[z - 1];
        }

        if (arr[z] == arr[i])
            z++;

        kmp[i] = z;
    }

    return kmp;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> x(n), y(2 * n);
    for (int i = 0; i < n; i++)
    {
        x[i] = b[i] ^ b[(i + 1) % n];
        y[i] = y[i + n] = a[i] ^ a[(i + 1) % n];
    }

    vector<int> kmp = Kmp(x, y);

    int nn = a.size(), mm = b.size();
    for (int i = 2*nn ; i < kmp.size()-1; i++)
    {
        if (kmp[i] == nn)
        {
            int k = (i - kmp[i] - nn);
            int x = b[0] ^ a[k];
            cout << k << " " << x << "\n";
        }
    }

    return 0;
}