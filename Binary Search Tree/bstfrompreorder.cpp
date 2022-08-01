/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

BinaryTreeNode<int>* solve(vector<int> &preorder,int mini,int max,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    
    if(preorder[i]<mini || preorder[i]>max){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i]);
    i++;
    
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,max,i);
    
    return root;
    
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i=0;
    int mini = INT_MIN;
    int max= INT_MAX;
    solve(preorder,mini,max,i);
}