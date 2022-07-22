#include<iostream>
#include<queue>
using namespace std;

class CircularQueue{
    
    int *arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        
        size = n;
        arr = new int[size];
        front=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front==0&&rear==size-1) || (rear==(front-1)%(size-1))){  
            //queue is full(rear can be just behind front)
           // cout<<"queue is full"<<endl;
            return false;
        }
        else if(front ==-1){  //no element
            front =rear=0;
        }
        else if(rear==size-1 &&front!=0){ 
            // rear at end (to maintain cyclic nature)
            rear=0;
        }
        else{//normal
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front==-1){
            // cout<<"queue is empty"<<endl;
            return -1;;
        }
        int ans = arr[front];
        arr[front]=-1;
        if(front==rear){ //single element
            front = rear=-1;
        }
        else if(front == size-1){
            front =0; //to maintain cyclic nature
        }
        else{ //normal
            front++;
        }
        return ans;
       
    }
};