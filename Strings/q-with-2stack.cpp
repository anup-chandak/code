#include <iostream>
#include <stack>

//#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;

void solve(){
    int n;
    cin>>n;
    int front;
    stack<int>s,ss;
    while(n--){
        string st;
        cin>>st;
        if(st=="push"){
            int x;
            cin>>x;
            if(s.empty())front=x;

            s.push(x);
        }
        else if(st=="front"){
            if(!ss.empty())cout<<ss.top()<<endl;
            else cout<<front<<endl;
        }
        else if(st=="pop"){
            if(!ss.empty()){
                cout<<ss.top()<<endl;
                ss.pop();
            }
            else {
                while(!s.empty()){
                    ss.push(s.top());
                    s.pop();
                }
                cout<<ss.top()<<endl;
                ss.pop();
            }
        }

    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}