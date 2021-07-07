#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int>s1;
    stack<int>s2;

    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s1.empty() and s2.empty()){
            cout<<"Queue is empty\n ";
            return -1;
        }

        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topVal = s2.top();
        s2.pop();
        return topVal;
    }

    bool isEmpty(){
        if(s1.empty() and s2.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    queue q; 
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<q.pop()<<endl;
    q.push(7);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.isEmpty();
    return 0;
}