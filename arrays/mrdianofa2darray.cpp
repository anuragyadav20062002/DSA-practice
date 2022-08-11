//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
    
    int numbergreatororequalto(vector<int> arr, int x ){
        int l =0;
        int h = arr.size()-1;
        
        while(l<=h){
            int mid = (l+h)/2;
            
            if(arr[mid]<=x){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        
        return l;
    }
 
 
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here          
         int s = 0;
         int e = 2001;
         
         
         
         while(s<=e){
             
            int mid = (s+e)/2;
            int count =0;
            
            for(int i=0;i<r;i++){
                count+=numbergreatororequalto(matrix[i],mid);
            }
            
            if((r*c)/2>=count){
                s=mid+1;
            }
            else{
                e =mid-1;
            }
             
         }
        return s;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends