//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    
    bool isFeasible(int arr[], int n, long long mid, int k){
        
        int painters = 1;
        long long boards = 0;
        
        for(int i=0; i<n; i++) {
            if(boards + arr[i] <= mid) {
                boards += arr[i];
                
            } else {
                painters++;
                if(painters > k or arr[i] > mid) {
                    return false;
                    
                } else {
                    boards = arr[i];
                }
            }
        }
        
        return true;
    }    
        
        
    //     for(long long i=0;i<n;i++){
    //         sum+=arr[i];
            
    //         if(sum>limit){
    //             sum=arr[i];
    //             painters++;
    //         }
    //     }
    //     return painters;
    // }
    
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long sum = 0;
        // int m = 0;
        
        for(int i=0;i<n;i++){
            // m = max(m,arr[i]);
            sum += arr[i];
        }
        
        long long low = 0;
        long long high = sum;
        long long ans = -1;
        
        while(low <= high){
            long long mid = low + (high-low)/2;
            
            // long long painters = isFeasible(arr,n,mid, k);
            
            if(isFeasible(arr, n, mid, k)) {
                ans = mid;
                high = mid-1;
                
            } else {
                low = mid+1;
                
            }
            
            // if(painters <=k)
            // high = mid-1;
            
            // else
            // low = mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends