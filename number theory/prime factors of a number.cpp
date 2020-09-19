#include<bits/stdc++.h>
using namespace std;
#define int1 long long

void sieve(int *p)
{
    p[0]=0;
    p[1]=0;
    p[2]=1;
    
    //primes.push_back(2);

    for(int1 i=3;i<=500000;i+=2)
        p[i]=1;

    for(int1 i=3;i<=500000;i+=2)
    {
        if(p[i]==1)
        {
            //primes.push_back(i);
            for(int1 j=i*i;j<=500000;j+=i)
                p[j]=0;
        }
    }
}

int main()
{
    int1 m;
    cin>>m;
    int l[500001]={0};
	vector<int> v,f;
    sieve(l);
    for(int1 i=0;i<=500000;i++)
    {
		if(l[i]==1)
			v.push_back(i);
	}
	int i=0;
	int p=v[0];
	while(p*p<=m)
	{
	    if(m%p==0)
	    {
	        f.push_back(p);
	        while(m%p==0)
	            m/=p;
	    }
	    i++;
	    p=v[i];
	}
	
	if(m!=1)
	    f.push_back(m);
	
	for(int i=0;i<f.size();i++)
	    cout<<f[i]<<endl;
}
