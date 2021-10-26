#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int min;
    Node* next;

    Node(int val) {
        this -> val = val;
        this -> next = nullptr;
    }
};

class MinStack {
    Node* head;
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (head == nullptr) {
            head = new Node(val);
            head -> min = val;
        } else {
            Node* newNode = new Node(val);
            newNode -> min = min(val, head -> min);
            newNode -> next = head;
            head = newNode;
        }
    }
    
    void pop() {
        head = head -> next;
    }
    
    int top() {
        return head -> val;
    }
    
    int getMin() {
        return head -> min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */