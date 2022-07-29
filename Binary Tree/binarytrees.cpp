#include<iostream>
#include<queue>
using namespace std;

class node {
  public:
    int data;
    node *left;
    node *right;

    node(int d){
      this->data = d;
      this->left = NULL;
      this->right = NULL;
    }
};

node* buildtree(node* root){
  cout << "enter data" << endl;
  int data;
  cin >> data;
  root = new node(data);

  if(data==-1){
    return NULL;
  }
  cout << "enter left data" << endl;
  root->left = buildtree(root->left);
  cout << "enter right data" << endl;
  root->right = buildtree(root->right);

  return root;
}

void levelOrderTraversal(node* root){
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    node *temp = q.front();
    q.pop();

    if(temp==NULL){
      //layer completed
      cout << endl;
      if(!q.empty())
      {
        //still child notes left
        q.push(NULL);
      }
      else{
        cout << temp->data << "";
        if(temp->left){
          q.push(temp->left);
        }
        if(temp->right){
          q.push(temp->right);
        }
      }
    }
  }
}

int main(){

  node *root = NULL;

  // CREATING
  root = buildtree(root);


  return 0;
} 