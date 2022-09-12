//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int> m;
        set<int> st;
        
        for(int i=0;i<str.length();i++)
        st.insert(str[i]);
        int n = st.size();
        int c=0;
        c++;
        int i=0;
        int j=1;
        m[str[i]]++;
        int mi = INT_MAX;
        
        while(i<=j and j<str.length()){
            if(c<n){
                if(m[str[j]]==0)c++;
                m[str[j]]++;
                j++;
            }
            
            else if(c==n){
                 mi = min(mi,j-i);
                if(m[str[i]]==1) c--;
                m[str[i]]--;
                i++;
            }
        }
        
        while(c==n){
             mi = min(mi,j-i);
            if(m[str[i]]==1) c--;
                m[str[i]]--;
                i++;
        }
        
        return mi;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends