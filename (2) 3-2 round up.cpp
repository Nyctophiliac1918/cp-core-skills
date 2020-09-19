#include <bits/stdc++.h>
using namespace std;

int main()
{
    long x,y;
    double z;
    cin>>x>>y;
    if(abs(x)>abs(y) && x%y!=0)
    {
        if(x/y<0)
            cout<<x/y;
        else cout<<x/y+1;
    }
    else if(abs(x)>abs(y) && x%y==0)
        cout<<x/y;
    else
    {
        z=(double)x/y;
        z=ceil(z);
        if(z==-0)
            z=0;
        cout<<z;
    }
}
