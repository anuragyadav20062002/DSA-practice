//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        map<char,int> mp;
       mp['M']=1000;
       mp['D']=500;
       mp['C']=100;
       mp['L']=50;
       mp['X']=10;
       mp['V']=5;
       mp['I']=1;
       int ans=0;
       for(int i=0;i<str.size();++i){
           if(i<str.size()-1 && mp[str[i]]<mp[str[i+1]]){
               ans+=mp[str[i+1]]-mp[str[i]];
               i++;
               continue;
           }
           ans+=mp[str[i]];
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends