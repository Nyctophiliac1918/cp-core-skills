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

ll exp(ll a, ll n)
{
    if (n == 0)
        return 1;
    return a * exp(a, n - 1);
}

int main() {
    
    ll a, n;
    cin >> a >> n;
    cout << exp(a, n);
}
