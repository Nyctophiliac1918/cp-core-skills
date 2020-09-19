#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int a[1000]={};
    a[0]=1;
    int j=2,n=1;
    int carry=0;
    while(j!=t+1)
    {
        for(int i=0;i<n;i++)
        {
            int product=a[i]*j+carry;
            a[i]=product%10;
            carry=product/10;
        }
        while(carry)
        {
            a[n]=carry%10;
            carry/=10;
            n++;
        }
        j++;
    }
    for(int i=n-1;i>=0;i--)
        cout<<a[i];
}
