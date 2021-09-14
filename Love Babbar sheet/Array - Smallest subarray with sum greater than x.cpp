// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here
        int s=0;
        vector<int>v(n+1);
        v[0]=0;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            v[i+1]=s;
        }
        int m = INT_MAX;
        for(int i=0;i<=n;i++)
        {
            int k = lower_bound(v.begin(),v.end(),v[i]-x) - v.begin() - 1;
            if(k>=0 && v[i]-v[k]>x)
                m=min(m,i-k);
        }
        return m;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends
