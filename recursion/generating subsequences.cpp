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

void generate_subsequences(char *in, char *out, int i, int j)
{
	if (in[i] == '\0')
	{
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	//rec case
	//include with current char
	out[j] = in[i];
	generate_subsequences(in, out, i + 1, j + 1);

	//exclude the current char
	generate_subsequences(in, out, i + 1, j);

}
int main()
{
	char input[] = "abc";
	char output[10];

	generate_subsequences(input, output, 0, 0);
}
