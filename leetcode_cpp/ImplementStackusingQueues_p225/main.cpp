//
//  main.cpp
//  ImplementStackusingQueues_p225
//
//  Created by 魏思哲 on 1/3/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        queue<int> stack;
    }

    /** Push element x onto stack. */
    void push(int x) {
        stack.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

    }

    /** Get the top element. */
    int top() {
        int result;
        result = stack.back();
        return result;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        bool result;
        result = stack.empty();
        return result;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    queue<int> stack;
    stack.push(3);
    stack.push(5);
    
    int result;
    while(!stack.empty()){
        result = stack.back();
        cout<<result<<",";
    }
    return 0;
}
