#include<bits/stdc++.h>

using namespace std;
using std::vector;
vector<int> processArray(std::vector<int> &arr ) {

  for (int i = 1; i < arr.size();i++){
    if((arr[i]>=10 && arr[i]<=99) && (arr[i-1]>=10 && arr[i-1]<=99)){
      arr.remove(arr.begin() + i);
      i--;
    }
  }

  return arr;
}

int main ( ){

  process
    
return 0;
}