#include <bits/stdc++.h>
/*#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
#include <cstring> //for memset()*/
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int validSteps(int x, int y, int X, int Y)
{
	if (x == X && y == Y)
		return 1;

	if (x > X or y > Y)
		return 0;

	int count = 0;
	count += validSteps(x + 1, y, X, Y);
	count += validSteps(x, y + 1, X, Y);

	return count;
}

int main()
{
	int m, n;
	cin >> m >> n;
	cout << validSteps(1, 1, n, m);
}
