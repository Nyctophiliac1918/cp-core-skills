// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	multiset<pair<int,char>>m;
    	for(int i=0;i<n;i++)
    	{
    	    m.insert({arr[i], 'a'});
    	    m.insert({dep[i], 'd'});
    	}
    	int mx=1, c=0;
    	for(auto it:m) {
    	    if(it.second == 'a')
    	        c++;
    	    else c--;
    	    mx=max(c,mx);
    	}
    	return mx;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
