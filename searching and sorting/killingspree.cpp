//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        if(n==0)
        return 0;
        
        if(n==1)
        return 1;
        
        
        int s=0;
        
        for(int i=1;i<n;i++){
            if((n-i*i) >=0 ){
                n=n-i*i;
                s++;
            }
            else if((n-i*i)<0){
                break;
            }
        }
        
        return s;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends