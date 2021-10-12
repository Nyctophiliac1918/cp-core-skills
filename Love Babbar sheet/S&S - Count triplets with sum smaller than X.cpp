// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    int i=0;
	    sort(arr,arr+n);
	    long long k=0;
	    while(i<n-2) {
	        int l=i+1, r=n-1;
	        long long s = sum - arr[i];
	       // cout<<s<<endl;
	        while(l<r)
	        {
	           // cout<<l<<" "<<r<<" "<<k<<endl;
	            if(s>arr[l]+arr[r])
	            {
	                k+=r-l;
	                l++;
	            }
	            else if(s<=arr[l]+arr[r]) r--;
	        }
	        i++;
	    }
	    return k;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
