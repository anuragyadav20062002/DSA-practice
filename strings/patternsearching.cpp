//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

bool searchPattern(string str, string pat)
{
    // your code here
    int n= str.length();
    int m = pat.length();
    
    int count=0;
    
    int i=0 , j=0,x=0;
    while(i<n && j<m)
    {  
        if(str[i++]==pat[j++])count++;
        else
        {   count=0;
            j=0;
            i = x++;
        }
    }
    
    if(count==m)return true;
    return false;
}



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}


// } Driver Code Ends