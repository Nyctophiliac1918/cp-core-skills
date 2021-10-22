// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    
    long long mergeSort(long long* arr, long long* tmp, int l, int r) {
        long long c = 0, m;
        if(l<r) {
            m = (l+r)/2;
            
            c += mergeSort(arr, tmp, l, m);
            c += mergeSort(arr, tmp, m+1, r);
            
            c += merge(arr,tmp,l,m,r);
        }
        return c;
    }
    
    long long merge(long long* arr, long long* tmp, int l, int m, int r) {
        long long c=0;
        int i=l, k=l, j=m+1;
        
        while(i<=m && j<=r) {
            if(arr[i]<=arr[j]){
                tmp[k++] = arr[i++];
            }
            else {
                c+=m-i+1;
                tmp[k++] = arr[j++];
            }
        }
        
        while(i<=m) tmp[k++] = arr[i++];
        while(j<=r) tmp[k++] = arr[j++];
        
        for(int i=l;i<=r;i++)
            arr[i] = tmp[i];
        
        return c;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long tmp[N];
        
        return mergeSort(arr, tmp, 0, N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
