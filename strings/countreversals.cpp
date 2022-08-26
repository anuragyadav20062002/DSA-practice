//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    stack<char> st;
    if(s.length()%2==1)
    return -1;
    int open =0;
    int close =0;
    
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        
        if(ch=='{'){
            st.push(ch);
            open++;
        }
        else if(ch=='}' && !st.empty() && st.top()=='{'){
            st.pop();
            open--;
        }
        else
        close++;
    }
    
    if(open%2==1)
    open = (open+1)/2;
    else
    open = open/2;
    
    if(close%2==1)
    close = (close+1)/2;
    else
    close = close/2;
    
    return open+close;
}