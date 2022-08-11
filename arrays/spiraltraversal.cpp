//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int fri = 0;
        int fci = 0;
        int lri= r-1;
        int lci = c-1;
        vector<int> ans;
        int total=r*c;
        int count=0;
        
        
        //printing first row
        while(count<total){
            
            for(int i = fci;count<total && i<=lci;i++){
            ans.push_back(matrix[fri][i]);
            count++;
        }
        fri++;
        
        //printing last column
        for(int i=fri;count<total && i<=lri;i++){
           ans.push_back(matrix[i][lci]);
           count++;
        }
        lci--;
        
        //printing last row
        for(int i=lci;count<total && i>=fci;i--){
            ans.push_back(matrix[lri][i]);
            count++;
        }
        lri--;
        
        //printing first column
        for(int i=lri;count<total && i>=fri;i--){
           ans.push_back(matrix[i][fci]);
           count++;
        }
        fci++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends