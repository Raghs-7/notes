#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int val) {
        value = val;
        next = nullptr;
    }
    ListNode(){
        value = 0;
        next = nullptr;
    }

};

void StackUsingArray(){

    class Stack{
    private:
        int* items = (int*)malloc(10*sizeof(int));
        int top;
        int size = 10;
    public:
        Stack(){
            top = -1;
        }

        bool IsFull(){
            return top == 9;
        }

        bool IsEmpty(){
            return top == -1;
        }

        void push(int value){
            if (IsFull()){
                // cout << "Stack is full" << endl;
                size += 10;
                items = (int*)realloc(items,size*sizeof(int));
            }
            items[++top] = value;
            return;
        }
        
        void pop(){
            if (IsEmpty()){
                cout << "Stack is Empty" << endl;
                return;
            }
            top--;
        }

        int peek(){
            if (top==-1) {
                cout << "Stack is Empty " << endl;
                return -1;
            }
            return items[top];
        }

    };
    return ;
}

void StackUsingLinkedList(){

    class Stack{
    private:
        ListNode* top;
    public:
        Stack(){
            top = nullptr;
        }        

        bool IsEmpty(){
            if (top==nullptr) return true;
            return false;
        }

        void push(int val){
            ListNode* newNode = new ListNode(val);
            newNode->next = top;
            top = newNode;
        }

        int pop(){
            ListNode* newNode = top;
            while (newNode->next){
                newNode = newNode->next;
            }
            int val = newNode->value;
            newNode = nullptr;
            delete newNode;
            return val;
        }

        int peek(){
            ListNode* newNode = top;
            while (newNode->next){
                newNode = newNode->next;
            }
            return newNode->value;
        }

        ~Stack(){
            while (!IsEmpty()){
                pop();
            }
        }
    };

    return ;
}

void StackUsingQueue(){
    // push(1)   1
    // push(3)   3, 1 ---> _, 1, 3
    // push(9)   _, 1, 3, 9 ---> _, _, _, 9, 3, 1


    // include queue using linked list
    class Queue{
    private:
        int size;
        ListNode* start;
        ListNode* end;
    public:
        Queue(){
            size = 0;
            start = nullptr;
            end = nullptr;
        }

        bool IsEmpty(){
            if (!size) return true;
            return false;
        }

        void push(int a){
            ListNode* newNode = new ListNode(a);
            if (IsEmpty()){
                start = newNode;
                end = newNode;
                size++;
                return;
            }
            else {
                end->next = newNode;
                end = end->next;
                size++;
                return;
            }
        }

        int pop(){
            if (IsEmpty()){
                cout << "Queue is empty" << endl;
                return -1;
            }
            else {
                ListNode* temp = start;
                start = start->next;
                int val = temp->value;
                delete temp;
                size--;
                if (size==0){
                    end = nullptr;
                }
                return val;
            }
        }

        int seek(){
            if (IsEmpty()){
                cout << "Queue is empty" << endl;
                return -1;
            }
            else {
                return start->value;
            }
        }

        int getSize(){
            return size;
        }
    };


    // main code
    class Stack{
    private:
        Queue* q;
    public:
        Stack(){
            q = new Queue();
        }

        void push(int x){  // O(n)
            int s = q->getSize();
            q->push(x);

            for (int i=1; i<s; i++){
                q->push(q->pop());
            }
        }

        int pop(){
            return q->pop();
        }

        int seek(){
            return q->seek();
        }

        bool IsEmpty(){
            return q->IsEmpty();
        }
    };
    return;
}


void QueueUsingArray(){

    class Queue{
    private:
        int size;
        int arr[10];
        int currSize;
        int start, end;
    public:
        Queue(){
            size = 10;
            start = -1;
            end = -1;
        }

        bool isEmpty(){
            return start == -1 && end == -1 && currSize == 0;
        }
        
        void push(int x){
            if (currSize==size) {
                cout << "Queue is full" << endl;
                return ; 
            }
            else if (currSize==0){
                start = 0;
                end = 0;
                arr[start] = x;
            }
            else{
                end = (end+1)%size;
                arr[end] = x;
                currSize++;
            }
        }

        int pop(){
            if (currSize==0){
                cout << "Queue is empty" << endl;
                return -1;
            }
            else if (currSize==1){
                int result = arr[start];
                start = -1;
                end = -1;
                currSize--;
                return result;
            }
            else {
                int result = arr[start];
                start = (start+1)%size;
                currSize--;
                return result;
            }
        }

        int seek(){
            if (currSize==0){
                cout << "Queue is empty" << endl;
                return -1;
            }
            else {
                return start;
            }
        }

        int size(){
            return currSize;
        }

    };

    return ;
}

void QueueUsingLinkedList(){

    class Queue{
    private:
        int size;
        ListNode* start;
        ListNode* end;
    public:
        Queue(){
            size = 0;
            start = nullptr;
            end = nullptr;
        }

        bool IsEmpty(){
            if (!size) return true;
            return false;
        }

        void push(int a){
            ListNode* newNode = new ListNode(a);
            if (IsEmpty()){
                start = newNode;
                end = newNode;
                size++;
                return;
            }
            else {
                end->next = newNode;
                end = end->next;
                size++;
                return;
            }
        }

        int pop(){
            if (IsEmpty()){
                cout << "Queue is empty" << endl;
                return -1;
            }
            else {
                ListNode* temp = start;
                start = start->next;
                int val = temp->value;
                delete temp;
                size--;
                if (size==0){
                    end = nullptr;
                }
                return val;
            }
        }

        int seek(){
            if (IsEmpty()){
                cout << "Queue is empty" << endl;
                return -1;
            }
            else {
                return start->value;
            }
        }

        int size(){
            return size;
        }
    };

    return;
}

void QueueUsingStack(){
    // will be using two stack data structures
    // push will be look like this
    // push(3) in stack --> 1, 2
    // s1 --> 1        s2 --> 
    // s1 -->          s2 --> 1 
    // s1 --> 2        s2 --> 1
    // s1 --> 2, 1     s2 --> 

    class Stack{
    private:
        int size;
        ListNode* top;
    public:
        Stack(){
            size = 0;
            top = nullptr;
        }        

        bool IsEmpty(){
            if (top==nullptr || size ==0 ) return true;
            return false;
        }

        void push(int val){
            ListNode* newNode = new ListNode(val);
            newNode->next = top;
            top = newNode;
            size++;
            return;
        }

        int pop(){
            ListNode* newNode = top;
            while (newNode->next){
                newNode = newNode->next;
            }
            int val = newNode->value;
            newNode = nullptr;
            delete newNode;
            size--;
            return val;
        }

        int peek(){
            ListNode* newNode = top;
            while (newNode->next){
                newNode = newNode->next;
            }
            return newNode->value;
        }

        int getSize(){
            return size;
        }

        ~Stack(){
            while (!IsEmpty()){
                pop();
            }
        }
    };

    // main code
    // approch-1
    class Queue{
    private:
        Stack* s1;
        Stack* s2;
    public:
        Queue(){
            s1 = new Stack();
            s2 = new Stack();
        }

        void push(int a){   // O(n)
            while (s1->getSize()){
                s2->push(s1->pop());
            }
            s1->push(a);
            while (s2->getSize()){
                s1->push(s2->pop());
            }
            return;
        }

        int pop(){
            return s1->pop();
        }

        bool IsEmpty(){
            return s1->IsEmpty();
        }

        int peek(){
            return s1->peek();
        }
    };


    // approch-2
    class Queue{
    private:
        Stack* s1;
        Stack* s2;
    public:
        Queue(){
            s1 = new Stack();
            s2 = new Stack();
        }

        void push(int a){   // O(n)
            s1->push(a);
        }

        int pop(){
            if (!s2->IsEmpty()){
                return s2->pop();
            }
            else {
                while (s1->getSize()){
                    s2->push(s1->pop());
                }
                return s2->pop();
            }
        }

        bool IsEmpty(){
            return s1->IsEmpty() && s1->IsEmpty();
        }

        int peek(){
            if (!s2->IsEmpty()) return s1->peek();
            else {
                while (s1->getSize()){
                    s2->push(s1->pop());
                }
                return s2->peek();
            }
        }
    };
    
    return;
}


void ExplainStack(){
    // LIFO --> Last In First Out
    // stack <int> st;
    // push(2)  2, 
    // push(3)  2, 3
    // push(4)  2, 3, 4
    // push(1)  2, 3, 4, 1
    // pop()    2, 3, 4
    // seek()    4
    // seek()    4
    // pop()    2, 3
    // push(5)  2, 3, 5
    // seek()    5
    // size()   3

    // Four Functions --> push, pop, top, size

    return ;
}


void ExplainQueue(){
    // FIFO --> First In First Out
    // push(2)  2, 
    // push(1)  2, 1
    // push(3)  2, 1, 3
    // push(4)  2, 1, 3, 4
    // pop()    1, 3, 4
    // seek()    1
    // pop()    3, 4
    // seek()    3
    // push(7)  3, 4, 7
    // top()    3
    // size()   3

    // Four Functions --> push, pop, top, size

    return ;
}

class min_stack{
private:
    stack<int> st;
    int m;
public:
    
    void push(int val){
        if (st.empty()){
            m = val;
            st.push(val);
        }
        else {
            if (val<m){
                m = val;
                st.push(2*val-m);
            }
            else {
                st.push(val);
            }
        }
    }

    void pop(){
        if (!st.empty()) {
            if (st.top()<m){
                m = 2*m-st.top();
                st.pop();
            }
            st.pop();
        }
    }
};

int main(){

    return 0;
}