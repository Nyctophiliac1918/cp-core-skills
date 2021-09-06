// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends


// Function to return minimum number of jumps to end of array
class Solution{
  public:
    int minJumps(int a[], int n){
        // Your code here
        if(n==1)
            return 0;
        if(a[0] == 0) return -1;
        
        int mxr=a[0], jumps = 1, steps = a[0];
        
        for(int i=1;i<n-1;i++) {
            mxr = max(mxr, i + a[i]);
            steps--;
            if(steps == 0)
            {
                steps = mxr - i;
                jumps++;
            }
            if(i>=mxr) return -1;
        }
        
        return jumps;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
