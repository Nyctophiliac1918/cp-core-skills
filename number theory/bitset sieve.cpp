//We will make a bitset of 10^7 elements so that it doesn't provide any runtime error. The basic idea to use bitset is to increase the number of prime numbers stored. As a bitset of size 100 will occupy only 100 bits in comparision to a bool or int vector which will use a size of 800 bits and 3200 bits, repectively.
//This prints out the first 100 prime numbers.


#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

const int n=10000000;
bitset<10000005>b;
vector<int>primes;

void sieve()
{
    b.set(); //set all bits to 1
    b[0] = b[1] = 0;
    for(long long i=2;i<=n;i++)
    {
        if(b[i])
        {
            primes.push_back(i);
            for(long long j=i*i;j<=n;j+=i)
                b[j]=0;
        }
    }
}

int main()
{
    sieve();
    for(int i=0;i<=100;i++)
        cout<<primes[i]<<" ";
}
