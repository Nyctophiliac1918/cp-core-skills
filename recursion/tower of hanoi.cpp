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

void move(int n, char src, char helper, char dest)
{
	//base case
	if (n == 0)
		return;

	//rec case
	//move n-1 disk from src to helper
	move(n - 1, src, dest, helper);
	cout << "Shift disk " << n << " from " << src << " to " << dest << endl;
	move(n - 1, helper, src, dest);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	move(n, 'A', 'B', 'C');
}
