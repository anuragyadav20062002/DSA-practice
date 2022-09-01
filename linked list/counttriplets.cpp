//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
  vector<int> arr;
    Node *t = head;
    while(t != NULL) {
        arr.push_back(t->data);
        t = t->next;
    }

    sort(arr.begin(), arr.end());
    int cnt = 0, n = arr.size();
    
    for(int k = 0; k < n - 2; ++k) {
        int i = k + 1, j = n - 1;

        while(i < j) {
            int sum = arr[k] + arr[i] + arr[j];
            if(sum == x)
                ++cnt;
            
            if(sum <= x)
                ++i;
            else 
                --j;
        }  
    }

    return cnt;
} 