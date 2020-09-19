//Mike found an interesting problem. In this problem you are given two integers, n and k. You need to find the the maximum value of x, such that, n! % kx = 0.
//Constraints 1<=T<=20 1<=n<=10^8 2<=k<=10^8

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;
#define N 100000005

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        long long ans=N;
        long long occ=0, cnt=0;
        if(k%2==0)
        {
            while(k%2==0)
            {
                occ++;
                k/=2;
            }
            long long p=2;
            while(p<=n)
            {
                cnt+=n/p;
                p*=2;
            }
            ans=min(ans,cnt/occ);
            //cout<<k<<" "<<ans<<endl;
        }
        for(int i=3;i*i<=k;i+=2)
        {
            if(k%i==0)
            {
                occ=0,cnt=0;
                while(k%i==0)
                {
                    occ++;
                    k/=i;
                }
                long long p=i;
                while(p<=n)
                {
                    cnt+=n/p;
                    p*=i;
                }
                ans=min(ans,cnt/occ);
                //cout<<k<<" "<<ans<<endl;
            }
        }
        cnt=0;
        if(k!=1)
        {
            long long l=k;
            while(l<=n)
            {
                cnt+=n/l;
                l*=k;
            }
            ans=min(ans,cnt);
            //cout<<k<<" "<<ans<<endl;
        }
        if(ans==N)
            cout<<0<<endl;
        else cout<<ans<<endl;
    }
}
