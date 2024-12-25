/*

Given an array of N integers, find the sum of XOR of all pairs of numbers in the array, sum of XOR of all subset of numbers in the array, sum of AND of all pairs of numbers in the array, sum of AND of all subset of numbers in the array. Calculate it %1000000007. 
For pair you should select two index i, j such that i<j.

Input Format
The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains a single integer N, (2<=N<=100000).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

Sum of N over all test cases does not exceed 10^6.

Output Format
For each test case output, 4 space-separated integers in a new line in the order the sum of XOR of all pairs of numbers in the array, sum of XOR of all subset of numbers in the array, sum of AND of all pairs of numbers in the array, sum of AND of all subset of numbers in the array. Since these numbers may be very large, compute them modulo 1000000007 (10^9+7)

Constraints
Sample Input 1
6
5
1 2 3 4 5
5
1 1 2 3 5
3
1 2 3
4
1 2 2 4
10
989098 987656790 989098765 234543 3456543 234567543 1234567 5678 56789 8909876
10
123 1234543 2345 6776 8787 8765467 234567 98765444 1234 4561
Sample Output 1
42 112 9 25
32 112 8 25
6 12 3 9
23 56 2 11
378768679 755809533 328561458 769714220
962949537 271171227 9132543 118419489
Note
1st test case: all pairs and corresponding XOR and AND value:
(1,2) - 3, 0
(1,3) - 2, 1
(1,4) - 5, 0
(1,5) - 4, 1
(2,3) - 1, 2
(2,4) - 6, 0
(2,5) - 7, 0
(3,4) - 7, 0
(3,5) - 6, 1
(4,5) - 1, 4
Sum of XOR of all pairs = 42, Sum of AND of all pairs = 9

3rd test case: all subset XOR and AND values:
(1) - 1, 1
(1,2) - 3, 0
(1,3) - 2, 1
(2,3) - 1, 2
(2) - 2, 2
(3) - 3, 3
(1,2,3) - 0, 0
Sum of XOR of all subset =  12, Sum of AND of all subset = 9

*/
#include <iostream>

#include<bits/stdc++.h>
 
 
using namespace std;
#define int long long int
 
const int M = 1e9 + 7; 
const int N = 1e7 + 1;

int bin_exp(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(ans*1ll*a)%M;
        a=(a*1ll*a)%M;
        b/=2;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    
    int arr[n];
    
    
    for(int i = 0; i < n ; i++)cin >> arr[i];
        
    map <int, int> mp;

    for(int i = 0; i < 31; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            if(arr[j] & (1 << i))mp[i]++;
        }
    }
    int x = 0, y;
    for(int i = 0; i < 31; i++)
    {
        y = 0;
        y = (bin_exp(2, i)*mp[i])%M;
        y = (y * (n - mp[i]))%M;
        x = (x+y)%M;
    }
    cout << x << " ";
    
    x = 0;
    for(int i = 0; i < 31; i++)
    {
        if(mp[i] == 0)continue;
        y = 0;
        y = (bin_exp(2, i)*bin_exp(2,(mp[i]-1)))%M;
        y = (y * bin_exp(2, n - mp[i]))%M;
        x = (x+y)%M;
    }
    cout << x << " ";
    
    x = 0;
    for(int i = 0; i < 31; i++)
    {
        if(mp[i] == 0)continue;
        y = 0;
        if(i == 0)
        {
            y = (bin_exp(2, i)*(mp[i]))%M;
            y = ((y* (mp[i] - 1))/2)%M;
        }
        else
        {
            y = (bin_exp(2, i-1)*(mp[i]))%M;
            y = ((y* (mp[i] - 1)))%M;
        }
        
        x = (x + y)%M;
    }
    cout << x << " ";
    
    x = 0;
    for(int i = 0; i < 31; i++)
    {       
        y = 0; 
        y = (bin_exp(2, i) * (bin_exp(2, mp[i])-1))%M;   
        x = (x + y)%M;  
    }
    cout << x << " ";
    
    cout << endl;
    
    
}
signed main()
{
    int t;
    cin >> t;

    while(t--)solve();
}
