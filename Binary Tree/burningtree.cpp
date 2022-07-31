//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
    //create mapping and return target
    Node* createparentmapping(Node* root,int target,map<Node*,Node*> &nodetoparent){
        Node* res=NULL;
        queue<Node* > q;
        q.push(root);
        
        nodetoparent[root]= NULL;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp->data==target){
                res=temp;
            }
            
            //mapping node to parent
            
            if(temp->left){
                nodetoparent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                nodetoparent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        
        return res;
        
    }
    
    
    int burntree( Node* root , map<Node*,Node*> &nodetoparent){
        
        map<Node*,bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root]=true;
        
        int ans=0;
       
        
        while(!q.empty()){
             
             bool flag=0;
             int size =q.size();
             
             for(int i=0;i<size;i++){
                 
                 Node* temp = q.front();
                 q.pop();
                 //checking all three pointers
                 
                 if(temp->left && !visited[temp->left]){
                     flag=1;
                     q.push(temp->left);
                     visited[temp->left]=1;
                 }
                 
                 
                 if(temp->right && !visited[temp->right]){
                     flag=1;
                     q.push(temp->right);
                     visited[temp->right]=1;
                 }
                 
                 if(nodetoparent[temp] &&!visited[nodetoparent[temp]]){
                     flag=1;
                     q.push(nodetoparent[temp]);
                     visited[nodetoparent[temp]]=1;
                 }
             }
             
             if(flag==1){
                 ans++;
             }
             
             
        }
        return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        map<Node*,Node*> nodetoparent;
        Node* targetnode = createparentmapping(root,target,nodetoparent);
        
      int ans = burntree(targetnode,nodetoparent);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends