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

int ser(int *a, int m, int l, int h)
{
    if (l > h)
        return -1;

    int mid = l + (h - l) / 2;
    if (a[mid] < m)
        return ser(a, m, mid + 1, h);
    else if (a[mid] > m)
        return ser(a, m, l, mid - 1);
    else return mid;
    //cout << n << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 2, 3, 4, 5, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << ser(arr, 5, 0, n - 1);
}
