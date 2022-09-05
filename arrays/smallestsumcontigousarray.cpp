//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int ans=INT_MAX;
      
      int l=0;
      int sum=0;
      for(int r=0;r<a.size();r++){
          sum+=a[r];
          ans=min(ans,sum);
          while(sum>0){
              sum-=a[l];
              l++;
          }
      }
      return ans;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends