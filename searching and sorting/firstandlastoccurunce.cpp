//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> find(int arr[],int n , int x){

          int f = -1 , l = -1 , b = 0 , e = n-1;
   while(b<e)
   {
       int m = b+(e-b)/2;
       if(arr[m]>=x){
           e=m;
       }
       else{
           b = m+1;
       }
   }

  if(arr[b] == x)
   {
       f=b ;
   }
   else{
       return {-1,-1};
   }
   
   b = f, e = n-1;

   while(b<e)
   {
        int m = b+(e-b)/2;
        if(arr[m] == x)
        {
            b = m;
            if(arr[e] ==x)
              {
                 b = e;
             }
        else{
            e--;
            }
        }
        else{
            e = m-1;
        }
   }

   l = b ;
   return {f,l};

}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends