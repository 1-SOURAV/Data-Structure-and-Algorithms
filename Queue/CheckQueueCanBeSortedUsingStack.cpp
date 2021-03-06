/*
Given a Queue consisting of first n natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:
1. Push and pop elements from the stack
2. Pop (Or enqueue) from the given Queue.
3. Push (Or Dequeue) in the another Queue.

Examples :

Input : Queue[] = { 5, 1, 2, 3, 4 }
Output : Yes
Pop the first element of the given Queue i.e 5.
Push 5 into the stack.
Now, pop all the elements of the given Queue and push them to
second Queue.
Now, pop element 5 in the stack and push it to the second Queue.
 
Input : Queue[] = { 5, 1, 2, 6, 3, 4 }
Output : No
Push 5 to stack.
Pop 1, 2 from given Queue and push it to another Queue.
Pop 6 from given Queue and push to stack.
Pop 3, 4 from given Queue and push to second Queue.
Now, from using any of above operation, we cannot push 5
into the second Queue because it is below the 6 in the stack.

Algorithm:
1. Initialize the expected_element = 1
2. Check if either front element of given Queue or top element of the stack have expected_element
….a) If yes, increment expected_element by 1, repeat step 2.
….b) Else, pop front of Queue and push it to the stack. If the popped element is greater than top of the Stack, return “No”.


Implementation:
*/


#include<bits/stdc++.h>
using namespace std;

bool check(queue<int>q, int n){
    //Varible to store the front element of the queue;
    int front;

    //Variable that tells us the excepted value at the particular time in the queue.
    //Intializing with one because we are given first n natural numbers in unsorted order.So in sorted order the first element of 
    //the queue will be 1.
    int expected = 1;

    stack<int>st;

    while(!q.empty()){
        front  = q.front();
        q.pop();

        //If front is equal to the expected values then simply incerease the expected
        if(front == expected){
            expected++;
        }

        else{
            if(st.empty()){
                st.push(front);
            }

            else if(front > st.top()){
                return false;
            }

            else {
                st.push(front);
            }
        }

        while(!st.empty() && st.top() == expected){
            st.pop();
            expected++;
        }
    }

    if(expected - 1 == n){
        return true;
    }

    return false;
}

int main(){
    queue<int>q;

    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    int n = q.size();

    if(check(q, n)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}