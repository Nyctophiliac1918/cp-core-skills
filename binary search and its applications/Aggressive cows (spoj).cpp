//In this question, a monotonic searh space is being made. https://www.spoj.com/problems/AGGRCOW/

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

bool canPlaceCows(int stalls[], int n, int c, int m)
{
	int lastOne = stalls[0];
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (stalls[i] - lastOne >= m)
		{
			//update the last cow placed.
			lastOne = stalls[i];
			cnt++;
			if (cnt == c)
				return true;
		}
	}
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	w(t)
	{
		int n, cows;
		cin >> n >> cows;

		int stalls[n];
		rep(i, n) cin >> stalls[i];

		sort(stalls, stalls + n);

		int s = 0, e = stalls[n - 1] - stalls[0];
		int ans = 0;
		//BS Algo
		while (s <= e)
		{
			int mid = s + (e - s) / 2;
			bool canCowsBePut = canPlaceCows(stalls, n, cows, mid);
			if (canCowsBePut)
			{
				ans = mid;
				s = mid + 1;
			}
			else e = mid - 1;
		}

		cout << ans << endl;
	}
}
