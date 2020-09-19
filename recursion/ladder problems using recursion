#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip> //for set precision
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int f(int n, int k)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;

	int ans = 0;
	for (int i = 1; i <= k; i++)
		ans += f(n - i, k);

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;         //k= max no of steps he could jump at a time.
	cin >> n >> k;
	cout << f(n, k);
}
