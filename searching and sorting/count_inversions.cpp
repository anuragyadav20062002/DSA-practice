//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  long long count{};
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],long long l,long long m,long long r){
        long long leftSize = m-l+1;
        long long rightSize = r-m;
        
        long long *leftArr = new long long[leftSize];
        long long *rightArr = new long long[rightSize];
        
        for(int i=0;i<leftSize;i++)
        leftArr[i]=arr[l+i];
        
        for(int i=0;i<rightSize;i++)
        rightArr[i]=arr[m+i+1];
        
        long long i{},j{},k{};
        
        while(i<leftSize && j<rightSize){
            if(rightArr[j] < leftArr[i]){
                count+=leftSize-i;
                arr[l+k]=rightArr[j];
                j++;
            }else{
                arr[l+k]=leftArr[i];
                i++;
            }
            k++;
        }
        while(i<leftSize){
            arr[l+k]=leftArr[i];
            i++;k++;
        }
        while(j<rightSize){
            arr[l+k]=rightArr[j];
            j++;k++;
        }
    }
    
    void mergeSort(long long arr[],long long l,long long r){
        if(l>=r)return;
        
        long long mid = (r-l)>>1;
        mid+=l;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends