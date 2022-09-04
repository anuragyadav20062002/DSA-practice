//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> pattern(int n){
        // code here
        int x = 1;
        int y = n*(n+1);
        vector<string> ans;
        
        for(int i=0 ; i<n ; i++){
            
            string temp = "";
            
            for(int j =0; j<2*i;j++){
                temp+='-';
            }
            
            int k = n-i;
            
            while(k){
                temp+= to_string(x);
                temp+='*';
                k--;
                x++;
            }
            
            k = n-i;
            int num = y-n+1;
            while(k){
                if(k==1){
                temp+= to_string(num);
                k--;
                num++;
                }
                else{
                temp+= to_string(num);
                temp+='*';
                k--;
                num++; 
                }
                y--;
            }
            y++;
            ans.push_back(temp);
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
        
        Solution ob;
        vector<string> ans = ob.pattern(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
// } Driver Code Ends