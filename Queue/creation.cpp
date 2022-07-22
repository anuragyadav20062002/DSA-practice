#include<iostream>
#include<queue>
using namespace std;

int main(){

  queue<int> q;

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  cout << "front is" << q.front();

  cout << "size is" << q.size() << endl;

  q.pop();
  q.pop();
  q.pop();

  cout << "front is" << q.front();

  cout << "size is" << q.size() << endl;

  if(q.empty()){
    cout << "empty";
  }

  return 0;
}