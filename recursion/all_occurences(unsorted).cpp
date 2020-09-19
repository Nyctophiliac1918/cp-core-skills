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

//only occurences
void occ(int *a, int i, int n, int m)
{
    if (i == n)
        return;

    if (a[i] == m)
        cout << i << " ";

    occ(a, i + 1, n, m);
}

//gives count too
int storeOcc(int *a, int i, int n, int m, int *out, int j)
{
    if (i == n)
        return j;

    if (a[i] == m)
    {
        out[j] = i;
        return storeOcc(a, i + 1, n, m, out, j + 1);
    }

    return storeOcc(a, i + 1, n, m, out, j);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a[] = {1, 2, 3, 4, 7, 10, 7, 30, 7, 93};
    int n = sizeof(a) / sizeof(a[0]);
    int out[100] = {0};
    int j = 0;
    int m = 7;

    occ(a, 0, n, m);
    cout << endl;

    cout << "Count = " << storeOcc(a, 0, n, m, out, 0) << endl;
    for (int i = 0; i < storeOcc(a, 0, n, m, out, 0); i++)
        cout << out[i] << " ";
}
