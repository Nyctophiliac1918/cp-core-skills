//https://codeforces.com/problemset/problem/26/A

#include<iostream>
#include<vector>
using namespace std;

//const int N=3005;

int sieve(int n)
{
    vector<int>p(n+1);
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        if(!p[i])
        {
            for(int j=i;j<=n;j+=i)
                p[j]++;
        }
    }
    for(int i=2;i<=n;i++)
    {
        cout<<p[i]<<endl;
        if(p[i]==2)
            ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<sieve(n);
}
