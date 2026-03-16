#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next ;
	Node* prev;

	Node(int a){
		val = a;
		next = nullptr;
		prev = nullptr;
	}
};

Node* LinkedListToArray(int* ptr, int n){
	int idx = 1;
	if (ptr==nullptr) return nullptr;
	Node* head = new Node(ptr[0]);
	Node* prv = head;
	while (idx<n){
		Node* temp = new Node(ptr[idx]);
		prv->next = temp;
		temp->prev = prv;
		prv = prv->next;
		idx++;
	}
	return head;
}
Node* delete_head(Node* head){

	if (head==nullptr || head->next == nullptr) return nullptr;

	Node* newhead = head->next;
	head->next = nullptr;
	newhead->prev = nullptr;
	delete head;

	return newhead;
}

Node* delete_tail(Node* head){

	if (head==nullptr || head->next == nullptr) return nullptr;
	Node* temp = head;
	while (temp->next){
		temp = temp->next;
	}

	Node* newtail = temp->prev;
	newtail->next = nullptr;
	temp->prev = nullptr;
	delete temp;

	return head;
}

Node* delete_kth_node(Node* head, int k){
	int cnt = 0;
	Node* temp = head;
	while (temp->next){
		cnt++;
		if (cnt==k) break;
		temp = temp->next;
	}
	Node* back = temp->prev;
	Node* nxt = temp->next;
	if (nxt == nullptr && back == nullptr){
		return nullptr;
	}
	else if (nxt==nullptr){
		return delete_tail(head);
	}
	else if (back==nullptr){
		return delete_head(head);
	}
	else {
		back->next = nxt;
		nxt->prev = back;
		temp->next = nullptr;
		temp->prev = nullptr;
		delete temp;
	}
	return head;
}

void print(Node* head){
	Node* temp = head;
	while (temp->next){
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* delete_by_value(Node* head, int num){
	Node* temp = head;
	while(temp->next){
		if (temp->val==num) break;
		temp = temp->next;
	}
	if (temp==nullptr){
		cout << num << " is not present " << endl;
		return head;
	}
	Node* back = temp->prev;
	Node* nxt  = temp->next;

	if (nxt==nullptr &&  back==nullptr){
		return nullptr;
	}
	else if (back==nullptr){
		return delete_head(head);
	}
	else if (nxt==nullptr){
		Node* newtail = temp->prev;
		newtail->next = nullptr;
		temp->prev = nullptr;
		delete temp;
		return head;
	}
	else {
		back->next = nxt;
		nxt->prev = back;
		temp->next = nullptr;
		temp->prev = nullptr;
		delete temp;
		return head;
	}
}

Node* reverse_DLL(Node* head){
	// bro if you think you can do it in O(n) without anything
	// just because it's a double linked list

	// brute force is
	// store all of them in a stack one by one
	// and then on just another traversal just pop and update the value
	// space complexity --> O(n)
	// time complexity --> O(2*n)


	// optimal solution
	// time complexity O(n)
	// space compelxity --> O(1)
	// []  []  []  basic intution of the solution is to swap the links
	if (head==nullptr || head->next == nullptr) return head;
	Node* temp = head;
	Node* last = nullptr;
	while (temp){
		last = temp->prev;
		temp->prev = temp->next;
		temp->next = last;
		temp = temp->prev;
	}
	head = last->prev;
	return head;
}

int main(){
	int arr[] = {12, 8, 9 ,5, 7, 3, 10};
	int size = sizeof(arr)/sizeof(arr[0]);
	Node* head = LinkedListToArray(arr, size);
	print(head);
	head = delete_head(head);
	cout << "after deletion of head" << endl;
	print(head);
	head = delete_tail(head);
	cout << "after deletion of tail" << endl;
	print(head);
	int k = 3;
	cout << "after deletion of third node" << endl;
	head = delete_kth_node(head, k);
	print(head);
	cout << "after deleting 9 from list" << endl;
	head = delete_by_value(head, 9);
	print(head);
	return 0;
}
