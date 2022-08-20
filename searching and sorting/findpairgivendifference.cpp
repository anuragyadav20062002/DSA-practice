//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

bool findPair(int arr[], int size, int n)
{
   sort(arr,arr+size);
   
   for(int i=0;i<size;i++)
   {
    int s=i;
    int e=size-1;
    int mid=s+(e-s)/2;
    
   while(s<=e && i!=mid)              
   { 
       if((arr[mid]-arr[i])==n)
       {
           return true;
       }
     else if((arr[mid]-arr[i])>n)
      {
         e=mid-1; 
          
      }
      
      else if((arr[mid]-arr[i])<n)
   {
      s=mid+1;
   }
   
      mid=s+(e-s)/2; 
       
   }
   
   }
   
  return false;
  
}