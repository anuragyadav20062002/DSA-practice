//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    void dfs (vector<vector<char> > ch, int i, int j , string target, int idx ){
        
         if(i<0 || j<0|| i==ch.size()||j==ch[0].size()||idx>=target.length()||
              target[idx]!=ch[i][j])
              return ;
              if(idx==target.length()-1)
                {ans++;
                return ;
                }
                char c=ch[i][j];
                ch[i][j]='0';
                dfs(ch,i+1,j,target,idx+1);
                dfs(ch,i-1,j,target,idx+1);
                dfs(ch,i,j+1,target,idx+1);
                dfs(ch,i,j-1,target,idx+1);
                ch[i][j]=c;
    }
    
    
    int ans;
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        
        ans =0;
        for(int i=0;i<mat.size();i++){
            for(int j =0; j<mat[0].size();j++){
                dfs(mat,i,j,target,0);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends