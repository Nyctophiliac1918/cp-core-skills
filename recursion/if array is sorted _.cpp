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

bool isSorted(int *a, int n)
{
    if (n == 0 || n == 1)
        return true;
    if (a[0] < a[1] && isSorted(a + 1, n - 1))
        return true;
    return false;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 2, 3, 4, 4500, 650, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isSorted(arr, n - 1);
}
