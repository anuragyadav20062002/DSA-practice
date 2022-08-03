
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int signum(int size1, int size2) {
    if(size1 == size2) {
        return 0;
    }

    else if( size1 > size2) {
        return 1;
    }

    else { //size1 < size2
        return -1;
    }
}


void getMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median) {

    switch( signum(maxi.size(), mini.size()) ) {

        case 0:
            if(element > median) {
                mini.push(element);
                median = mini.top();

            } else {
                maxi.push(element);
                median = maxi.top();
            }
        break;

        case 1:
            if(element > median) {
                mini.push(element);
                median = (maxi.top() + mini.top())/2;

            } else {

                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (maxi.top() + mini.top())/2;
            }
        break;

        case -1:
            if(element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (maxi.top() + mini.top())/2;

            } else {
                maxi.push(element);
                median = (maxi.top() + mini.top())/2;

            } 
        break;   
    }
}


vector<int> findMedian(vector<int> &arr, int n){

// Write your code here 
    
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;

    for(int i=0; i<n; i++) {
        getMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
  return ans;
}
