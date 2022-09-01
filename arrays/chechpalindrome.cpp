//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    {
        int count = 0;
    	for(int i = 0; i < n; i++){
    	    if(check_pal(a[i])) 
    	    {
    	        count++;
    	    }
    	}
    	return n == count;
    }
    bool check_pal(int num){
        int val = num;
        int sum = 0;
       do
        {
         sum = (sum * 10) + num%10;
         num = num / 10;
     } while (num != 0);
        return sum == val;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends