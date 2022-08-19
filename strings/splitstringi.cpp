//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int zero=0;
        int one =0;
        int count=0;
        
        for(int i=0;i<str.length();i++){
            if(str[i]=='0') 
            zero++;
            else 
            one++;
            if(zero==one) 
            count++;
        }
        if(zero==one)
        return count;
        else
        return -1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends