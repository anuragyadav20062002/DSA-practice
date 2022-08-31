//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
     int a=0,b=0;
   // int one = 1;
  char one = '1', zero = '0';
   for(int i=0;i<S.length();i++){
       // index start with 010101
       if(S[i]==one){
           a++;
       }
       if(S[i]==zero){
           b++;
       }
       swap(zero,one);
       
   }
   return min(a,b);   
}