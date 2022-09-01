//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
   public:
   bool fact(int n, int mid)
   {
       
     int c = 0;
     int prod = 5;
     while(prod<=mid)
     {
         c +=  (mid/prod);
         prod *= 5;
     }
     return c>=n;
   }
   
       int findNum(int n)
       {
       //complete the function here
       if(n == 1) return 5;
       int low = 0,high = 1e9;
       while(high - low>1)
       {
           int mid = low + (high - low)/2;
           if(fact(n,mid))
           {
               high = mid;
           }
           else
           {
               low = mid;
           }
       }
       return high;
       }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends