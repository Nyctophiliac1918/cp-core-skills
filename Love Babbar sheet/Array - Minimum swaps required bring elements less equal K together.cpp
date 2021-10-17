// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        unordered_map<int,int>m;
        int p=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
                m[arr[i]]=1, p++;
            else m[arr[i]]=0;
        }
        for(int i=0;i<p;i++) {
            if(m[arr[i]]==0)
               c++; 
        }
        int l=0, r=p;
        int mx=0;
        mx=max(mx,c);
        while(r<n) {
            if(m[arr[r]]==0)
                c++;
            if(m[arr[l]]==0)
                c--;
            mx = min(mx,c);
            r++;
            l++;
        }
        return mx;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends
