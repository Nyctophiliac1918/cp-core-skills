#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005], pre[100005];

int main()
{
    int n;
    cin>>n;
    memset(pre, 0, sizeof(pre));
    pre[0]=1;

    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        sum%=n;             //I guess both these lines are one of the same.
        sum=(sum+n)%n;      //I guess both these lines are one of the same.
        pre[sum]++;
    }

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int m=pre[i];
        ans+=m*(m-1)/2;
    }
    cout<<ans;
}
