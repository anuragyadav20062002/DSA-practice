//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    
    bool isPossible(int mid, int N, vector<int>&A){
        int donuts =0;
        int n = A.size();
        
        for(int i=0;i<n;i++){
            int timetaken = 0;
            int timewilltake = A[i];
            
            while(timetaken+timewilltake <=mid){
                donuts++;
                if(donuts >=N)
                return true;
                
                timetaken+=timewilltake;
                timewilltake+=A[i];
            }
        }
        
        return false;
    }
    
    
    
    public:
    int findMinTime(int N, vector<int>&A, int L){
        //write your code here
        sort(A.begin(),A.end());
        
        int l =A[0]; //best case which takes min time to make donuts
        int h = A[L-1]* N*(N+1)/2; //worst case which takes max time to make donut
        
        
        int ans =0;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(isPossible(mid,N,A)){
                ans= mid;
                h= mid-1;
            }
            
            else{
                l=mid+1;
            }
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
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends