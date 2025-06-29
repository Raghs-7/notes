#include<iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;
	Node(int a){
		val = a;
		next = nullptr;
	}
};

bool LoopDetection(Node* head){
	// Time complexity --> O(n)
	// space complexity --> O(1)

	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next){
		slow = 	slow->next;
		fast = fast->next->next;
		if (fast==slow) return true;
	}
	return false;
}


int lengthOfLoop(Node* head){
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if (fast==slow) break;
	}
	if (fast==nullptr) return -1;
	Node* temp = fast;
	int length = 0;
	while (temp!=fast){
		fast = fast->next;
		length++;
	}
	return length;
}

Node* starting_cycle_Node(Node* head){
	// if root not existing return null

	// better solution
	// time complexity --> O(2*n)
	//int cycle_length = lengthOfLoop(head);
	//if (cycle_length==-1) return nullptr;
	//Node* start = head;
	//Node* end = head;
	//int cnt = 0;
	//while (cnt!=cycle_length){
	//	cnt++;
	//	end = end->next;
	//}
	//while (start!=end){
	//	start = start->next;
	//	end = end->next;
	//}
	//return start;

	// optimal appraoch
	// lecture 17
	// time complexity --> O(n)
	// space complexity --> O(1)
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if (slow==fast ){
			slow = head;
			while (slow!=head){
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return nullptr;
}

Node* remove_duplicate(Node* head){// in sorted linked list

}

Node* reverse(Node* head){
	// triversal approach
	Node* prev = nullptr;
	Node* front;
	Node* temp = head;
	while (temp){
		front = temp->next;
		temp->next = prev;
		prev = temp;
		temp = front;
	}
	return prev;
	// time complexity --> O(n)
	// space compelexit --> O(1)
}

Node* reverse_usingRecurssion(Node* head){
	// using recurssion
	if (head==nullptr || head->next == nullptr){
		return head;
	}
	Node* newHead = reverse_usingRecurssion(head->next);
	Node* front = head->next;
	front->next = head;
	head->next = nullptr;
	return newHead;

}

bool check_palandrom(Node* head){
	// you can first store every value in a stack and then compare
	// time complexity --> O(2*n)
	// space complexity --> O(n)

	// optimal
	// time complexity --> O(2*n)
	// space complexity --> O(1)

	// intution is first recognize the secound half
	// and then reverse their links and then compare

	// first find the middle
	if (head==nullptr||head->next==nullptr) return true;
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next && fast->next->next){//extra condition is added because in case of even no. of nodes we want the first middle element
		slow = slow->next;
		fast = fast->next->next;
	}

	Node* newHead = reverse(slow->next);
	Node* first = head;
	Node* secound = newHead;
	bool result = true;
	while (secound){
		if (first->val!=secound->val){
			result = false;
			break;
		}
		first = first->next;
		secound = secound->next;
	}
	reverse(newHead); // very important undo the changes
	return result;
}

Node* finding_intersection_Y_linkedlist(Node* head1, Node* head2){
	// if they never collide then return nullptr
	// you can do it like first find the length of both the linked list
	// then find which one is longer, let say their length are n1 and n2 and n1 > n2
	// then one which is longer just move it untill it's remaining length equals to the smaller one
	// after that just do if while node1->val!=node2->val then move both of them the moment you find similar value then just break it and return that node 
	// time complexity --> O(n1+2*n2)
	// space complexity --> O(1)

	// we will implement the same thing but in better way
	//  [] [] [] [] [] [] []
	//			  [] [] [] [] [] []
	//	  [] [] [] [] []

	Node* t1 = head1;
	Node* t2 = head2;

	while(t1!=t2){
		t1 = t1->next;
		t2 = t2->next;

		if (t1==t2) return t1;

		if (t1==nullptr) t1= head2;
		if (t2==nullptr) t2 = head1;
	}
	return t1;

}


Node* reverse_kth_group(Node* head){
	// input --> 1 2 3 4 5 6 7 8 9 10 and k =3
	// output -->3 2 1 6 5 4 9 8 7 10


}


int main(){

	return 0;
}
