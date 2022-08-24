//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
         // code here 
       int n=S.length();
       auto itr=S.begin();
       auto start=S.begin();
       auto itr1=S.begin();
       for(int i=0;i<n;i++){
           itr1++;
           if(S[i]=='.'){
               reverse(start,itr);
               start=itr1;
           }
           itr++;
       }
       reverse(start,S.end());
       reverse(S.begin(),S.end());
       return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends