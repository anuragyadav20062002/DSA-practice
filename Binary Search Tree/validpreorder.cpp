//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int i=0;
    void f(int lo,int hi,int pre[], int N){
        if(i>=N || pre[i]>hi || pre[i]<lo) return ;
        
        //virtually assing value to node and incrementing i
        int lim=pre[i++];
        //left child call
        f(lo,lim,pre,N);
        //right child call
        f(lim,hi,pre,N);
    }
    int canRepresentBST(int arr[], int N) {
        f(INT_MIN,INT_MAX,arr,N);
        //i has reached the end hence all numbers in the array can be assigned as nodes
        if(i>=N) return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends