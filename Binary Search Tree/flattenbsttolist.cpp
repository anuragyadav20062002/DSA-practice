/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void inorder(TreeNode<int>* root, vector<int> &in){
        if(root==NULL){
            return;
        }
        
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
        
    }

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> val;
    inorder(root,val);
    
    TreeNode<int>* newroot = new TreeNode<int>(val[0]);
    TreeNode<int>* curr= newroot;
    
    for(int i=1;i<val.size();i++)
    {
        TreeNode<int>* temp = new TreeNode<int>(val[i]);
        
        curr->left=NULL;
        curr->right= temp;
        curr=temp;
    }
    
    curr->left= NULL;
    curr->right= NULL;
    
    return newroot;
    
}
