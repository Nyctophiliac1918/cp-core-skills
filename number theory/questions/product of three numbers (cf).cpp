/*You are given one integer number n. Find three distinct integers a,b,c such that 2≤a,b,c and a⋅b⋅c=n or say that it is impossible to do it.
n (2≤n≤109)
For each test case, print the answer on it. Print "NO" if it is impossible to represent n as a⋅b⋅c for some distinct integers a,b,c such that 2≤a,b,c.
https://codeforces.com/problemset/problem/1294/C */

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
#define ll long long
#define pb push_back

int main(){

    int t;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>k;
        ll n=k;
        map<int,int>m;
        if(k%2==0)
        {
            m[2]=0;
            while(k%2==0)
            {
                m[2]++;
                k/=2;
            }
        }
        for(int i=3;i*i<=k;i+=2)
        {
            if(k%i==0)
            {
                m[i]=0;
                while(k%i==0)
                {
                    m[i]++;
                    k/=i;
                }
            }
        }
        //cout<<k<<endl;
        if(k!=1)
        {
            m[k]=1;
        }
        //cout<<m.size()<<endl;
        if(m.size()>=3)
        {
            cout<<"YES"<<endl;
            auto it=m.begin();
            ll a=it->first;
            cout<<a<<" ";
            it++;
            ll b=it->first;
            cout<<b<<" ";
            cout<<n/(a*b)<<endl;
            
        }
        else if(m.size()==1)
        {
            auto it=m.begin();
            if((it->second)>=6)
            {
                cout<<"YES"<<endl;
                ll a=pow(it->first,1), b=pow(it->first,2);
                cout<<a<<" "<<b<<" "<<n/(a*b)<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else 
        {
            auto it=m.begin();
            ll a=it->first;
            it++;
            ll b=it->first;
            //cout<<" "<<it->second+i->second;
            if(n/(a*b)!=a && n/(a*b)!=b && n/(a*b)!=1)
            {
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<n/(a*b)<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
}
