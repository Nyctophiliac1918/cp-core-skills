#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip> //for setprecision()
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


float sq_root(int n, int p) //BS for integer part and brute force for decimal part.
{
	int l = 0, r = n;
	float ans = -1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (mid * mid == n)
			return mid;
		else if (mid * mid < n)
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	float inc = 0.1;
	for (int times = 1; times <= p; times++)
	{
		while (ans * ans <= n)
			ans = ans + inc;

		ans -= inc;
		inc /= 10;
	}

	return ans;
}

int main()
{
	int n, p; //number of digits required after the integer part.
	cin >> n >> p;
	cout << sq_root(n, p);
}
