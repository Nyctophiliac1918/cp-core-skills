//O(N*log(logN))
//In this approach, we will consider that every odd number is prime at first.

#include<bits/stdc++.h>
using namespace std;
#define int1 long long

void sieve(int *p)
{
    p[0]=0;
    p[1]=0;
    p[2]=1;

    for(int1 i=3;i<=1000000;i+=2)
        p[i]=1;

    for(int1 i=3;i<=1000000;i+=2)
    {
        if(p[i]==1)
        {
            for(int1 j=i*i;j<=1000000;j+=i)     //We do i*i as suppose there's one less than 25 = 24. So, if it has it will have some divisors which will be less than sq root(24), basically from 2 to 24, if it doesn't have any than there's no chance that it will have divisors greater than sq root(24). As inthe case of 25, if ther's one more chance if it can have a divisor is that of its square root, i.e, 5. Thus, we can start iterating from i*i.
                p[j]=0;
        }
    }
}

int main()
{
    int1 n;
    cin>>n;
    int p[1000005]={0};
    sieve(p);
    for(int1 i=0;i<=n;i++)
        if(p[i]==1)
            cout<<i<<" ";
}
