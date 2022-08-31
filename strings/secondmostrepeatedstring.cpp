//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> m;
        
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        
        vector<pair<int,string>> vp;
        
        for(auto&value:m){
            vp.push_back({value.second,value.first});
        }
        
        sort(vp.begin(),vp.end());
        
        return vp[vp.size()-2].second;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends