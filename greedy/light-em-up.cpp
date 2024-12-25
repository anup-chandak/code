/*
Description
There are n light bulbs in a row. Each bulb is either on or off given in input as 1 or 0 respectively.

In one operation you can select any k consecutive bulbs and flip their switches, that is, if a bulb was off it becomes on and vice versa.

Find minimum number of operations to turn all the bulbs on. If it's impossible to do so print -1.

Input Format
First line of input contains T, number of test cases.

First line of each test case contains n and k.

Second line contains n integers, ith integer si represents the state of the ith bulb.

 

Output Format
For each testcase if its possible to turn all the bulbs on, print the minimum operations required, else print -1.

Constraints
T ≤ 1000

0 ≤ k ≤ n ≤ 2*105

si = {0,1}

Sum of n over all test cases is less than 2*105.

Sample Input 1
1
5 1
0 1 0 1 1
Sample Output 1
2
Note
Perform the operation on the subarrays(1 indexed): [1..2] and [2..3] to get 1 1 1 1 1 .
*/

#include <iostream>

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    vector<int>prefix(n+1,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    int cnt=0;
    for(int i=0;i<(n-k+1);i++)
    {
        if(i!=0)prefix[i]+=prefix[i-1];
        if((arr[i]==0 && prefix[i]%2==0) || (arr[i]==1 && prefix[i]%2==1))
        {
            prefix[i]+=1;
            prefix[i+k]-=1;
            cnt++;
        }
    }

    //we can no longer make a flip of k size
    bool flag=1;
    for(int i=(n-k+1);i<n;i++)
    {
        prefix[i]+=prefix[i-1];
    }

    for(int i=0;i<n;i++)
    {
        if((arr[i]==0 && prefix[i]%2==0) || (arr[i]==1 && prefix[i]%2==1))
        {
            flag=0;
        }
    }

    if(flag==0) cout<<"-1"<<endl;
    else cout<<cnt<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
}