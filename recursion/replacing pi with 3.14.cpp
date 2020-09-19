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

void replacePi(char a[], int i)
{
	//base case
	if (a[i] == '\0' or a[i + 1] == '\0')
		return;

	//looking for pi
	if (a[i] == 'p' and a[i + 1] == 'i')
	{
		//shifting+replacement of pi
		int j = i + 2;

		//take j to the end of the array
		while (a[j] != '\0')
			j++;

		//shifting from right to left
		while (j >= i + 2)
		{
			a[j + 2] = a[j];
			j--;
		}

		//replacement + recursive call for remaining part
		a[i] = '3';
		a[i + 1] = '.';
		a[i + 2] = '1';
		a[i + 3] = '4';
		replacePi(a, i + 4);

	}
	else replacePi(a, i + 1);

	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char a[1000];
	cin >> a;
	replacePi(a, 0);
	cout << a << endl;
}

//input xpighpipihujpi
//output x3.14gh3.143.14huj3.14
