// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    // your code here
    int c=0, e=0;
    for(int i=0;i<size;i++) {
        int x = a[i];
        if(c==0)
        {
            e=x;
            c++;
        }
        else {
            if(e==x)
                c++;
            else c--;
        }
    }
    int l=0;
    for(int i=0;i<size;i++) {
        if(a[i]==e)
            l++;
    }
    // printf("%d %d", e, l);
    
    return l>size/2 ? e : -1;
        
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends
