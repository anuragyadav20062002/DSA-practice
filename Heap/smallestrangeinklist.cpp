//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Node{
    public:
    int data;
    int row;
    int col;
    
    Node(int data,int i, int j){
        this->data= data;
        row=i;
        col=j;
    }
};

class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data>b->data;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          int mini = INT_MAX, maxi = INT_MIN;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    //insert first elements of all lists in heap
    for(int i=0; i<k; i++) {
        int element = KSortedArray[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini, end = maxi;

    //process ranges
    while(!minHeap.empty()) {

        //fetch mini
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp -> data;


        //range or answer
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        //next element exist, then update maxi
        if(temp->col + 1 < n) {
            maxi = max(maxi, KSortedArray[temp->row][temp->col + 1]);
            minHeap.push(new Node(KSortedArray[temp->row][temp->col + 1], temp->row, temp->col + 1));

        } else {
            break;

        }
    }
    pair<int, int> ans = make_pair(start,end);
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
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends