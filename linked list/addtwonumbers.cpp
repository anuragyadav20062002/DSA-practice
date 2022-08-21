//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    // Reverse Linked List
    Node* reverse(Node* root){
        Node* prev = NULL;
        Node* temp=root;
        Node* next1=root;
        while(temp!=NULL){
            next1=next1->next;
            temp->next=prev;
            prev=temp;
            temp=next1;
        }
        return prev;
    }
    Node*head=NULL;
    Node *tail=NULL;
    
    
    // Create new Node
    void node(int x){
           Node* new_node=new Node(x);
          if(head==NULL){
                head=new_node;
                tail=new_node;
            }
            else{
                tail->next=new_node;
                tail=tail->next;
            }
            
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        Node* temp1=reverse(first);
        Node* temp2=reverse(second);
         int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int x=temp1->data+temp2->data+carry;
             int a=x%10;
           node(a);
          
            carry=x/10;
            temp1=temp1->next;
            temp2=temp2->next;
        }
       
        while(temp1!=NULL){
                int x=temp1->data+carry;
                int a=x%10;
                node(a);
                carry=x/10;
                 temp1=temp1->next;
        }
         while(temp2!=NULL){
                int x=temp2->data+carry;
                int a=x%10;
                node(a);
                carry=x/10;
                 temp2=temp2->next;
        }
         if( carry==1){
            node(carry);
        }
        Node* head1=reverse(head);
        return head1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends