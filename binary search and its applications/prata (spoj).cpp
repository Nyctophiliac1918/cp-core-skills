#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

bool possible(int a[], int p, int l, int m)
{
	int c = 0;
	for (int i = 0; i < l; i++)
	{
		int n = a[i];
		ll sum=0;
		while (sum <= m)
		{
			c++;
			sum+=n;
			//cout<<sum<<" "<<c<<endl;
			n += a[i];
		}
		c--;
		if (c >= p)
		    return true;
	}
	return false;
}

int main()
{

	w(t)
	{
		int p, l;
		cin >> p >> l;
		int a[l];
		rep(i, l) cin >> a[i];
		int m = *min_element(a, a + l);
		ll b = (p * (2 * m + (p - 1) * m)) / 2;
		int s = 0, e = b, ans = INT_MAX;

		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (possible(a, p, l, mid))
			{
				ans = mid;
				e = mid - 1;
			}
			else s = mid + 1;
		}

		cout << ans << endl;
	}
}
