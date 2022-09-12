//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int cunt =0;
        
        while(!q.empty()){
            pair<int,int> front = q.front();
            int i = front.first;
            int j = front.second;
            
            if((i==-1 && j==-1) && q.size()==1){
                q.pop();
                break;
            }
            
            else if((i==-1 && j==-1) && q.size()>1){
                cunt++;
                q.pop();
                q.push({-1,-1});
            }
            
            else{
                //up
                if(i-1>=0 and grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                //left
                if(j-1>=0 and grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                //right
                 if(j+1<m and grid[i][j+1]==1){
                     grid[i][j+1]=2;
                    q.push({i,j+1});
                }
                //down
                if(i+1<n and grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                q.pop();
            }
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return cunt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends