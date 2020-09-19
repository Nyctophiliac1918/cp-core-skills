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

int lastOcc(int *a, int n, int m)
{
    if (n == 0)
        return -1;

    int i = lastOcc(a + 1, n - 1, m);
    if (i == -1)
    {
        if (a[0] == m)
            return 0;
        else return -1;
    }

    return i + 1;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a[] = {1, 2, 3, 4, 7, 10, 7, 30, 7, 93};
    int n = sizeof(a) / sizeof(a[0]);
    int m = 7;
    cout << lastOcc(a, n, m);
}
