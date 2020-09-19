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

int firstOcc(int *a, int n, int m)
{
    if (n == 0)
        return -1;

    if (a[0] == m)
        return 0;
    int i = firstOcc(a + 1, n - 1, m);
    if (i == -1)
        return -1;
    return i + 1;
}

//different way, same as a for loop.
int firstOcc(int *a, int i, int n, int m)
{
    if (i == n)
        return -1;
    if (a[i] == m)
        return i;
    return firstOcc(a, i + 1, n, m);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a[] = {1, 2, 3, 4, 7, 10, 20, 30};
    int n = sizeof(a) / sizeof(a[0]);
    int m = 30;
    cout << firstOcc(a, n, m) << endl;
    cout << firstOcc(a, 0, n, m) << endl;
}
