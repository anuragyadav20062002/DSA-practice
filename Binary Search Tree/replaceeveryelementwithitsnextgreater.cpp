//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Node{
   public:
   int data;
   Node* left;
   Node* right;
   Node(int x){
       data = x;
       left = NULL;
       right = NULL;
   }
};

Node* insert(Node* root,int value,Node*& suc){
   if(root == NULL){
       return new Node(value);
   }
   
   if(value < root->data){
       suc = root;
       root->left = insert(root->left,value,suc);
   }
   if(value >= root->data){ 
       root->right = insert(root->right,value,suc);
   }
   
   return root;
}

class Solution{
   public:
   vector<int> findLeastGreater(vector<int>& arr, int n) {
       vector<int> ans(n,0);
       Node* root = NULL;
       for(int i=n-1;i>=0;--i){
           Node* suc = NULL;
           root = insert(root,arr[i],suc);
           
           if(suc == NULL){
               ans[i] = -1;
           }else
               ans[i] = suc->data;
       }
       
       return ans;
   }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends