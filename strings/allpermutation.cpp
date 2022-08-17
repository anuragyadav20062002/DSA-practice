//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void solve( int index,set<string> &ans, string &S, int n){
        if(index==n){
            ans.insert(S);
            return;
        }
        
        for(int j=index;j<n;j++){
            swap(S[j],S[index]);
            solve(index+1,ans,S,n);
            //backtracking
            swap(S[j],S[index]);
        }

    }

	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    int index =0;
		    solve(index, ans , S, S.size());
		    return vector<string>(ans.begin(),ans.end());
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends