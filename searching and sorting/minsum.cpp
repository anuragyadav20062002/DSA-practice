//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   string solve(int arr[], int n) {
       sort(arr,arr+n);
       string ans="";
       int i=n-1;
       int carry=0;
       while(i>=0){
           if(arr[i]==0)break;
           int num1=arr[i--];
           int num2=0;
           if(i>=0)num2=arr[i--];
           int sum=num1+num2+carry;
           if(sum>9){
               carry=sum/10;
               sum=sum%10;
           }
           else carry=0;
           ans+=to_string(sum);
       }
       if(carry>0)ans.push_back(carry+'0');
       reverse(ans.begin(),ans.end());
       return ans;
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends