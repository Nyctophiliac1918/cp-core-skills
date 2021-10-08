// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> v){
        // code here
        int n = v.size();
        int i=n-1;
        for(i;i>0;i--) {
            if(v[i]>v[i-1])
                break;
        }
        if(i==0)
        {
            sort(v.begin(),v.end());
            return v;
        }
        int j=n-1;
        for(j;j>=i;j--)
            if(v[j]>v[i-1])
                break;
        swap(v[j],v[i-1]);
        sort(v.begin()+i,v.end());
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
