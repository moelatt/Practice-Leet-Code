#include "main.h"
// Add Two Numbers. Using Link List ===> (Medium)
// 2 => 3 list1
// 9 => 5 list2
// 1 => 9  result carry over 1 to next list
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
class ListNode{
	public:
	int data;
	ListNode *next;
	ListNode(int x) : data(x), next(NULL) {}
};

class LinkList {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *newList = new ListNode(0);
		ListNode *tail = newList;

		ListNode *firstList = l1;
		ListNode *SecondList = l2;

		int carryOver = 0;
		while(firstList != NULL || SecondList != NULL){
			int sumEachList = carryOver;
			if(firstList != NULL){
				sumEachList = sumEachList + firstList->data;
				firstList = firstList->next;
			}
			if(SecondList != NULL){
				sumEachList = sumEachList + SecondList->data;
				SecondList = SecondList->next;
			}
			if(sumEachList > 9 ){
				carryOver = 1;
				sumEachList = sumEachList - 10;
			}
			else{
				carryOver = 0;
			}
			ListNode *newList = new ListNode(sumEachList);
			tail->next = newList;
			tail = tail->next;
		}
		if(carryOver > 0){
			ListNode *newList = new ListNode(carryOver);
			tail->next = newList;
		}
		return newList->next;
	}
};
void printList(ListNode* n) { 
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
		cout << endl;
} 
int main(){
	ListNode *head = new ListNode(2); 
	ListNode *second = new ListNode(4); 
	ListNode *third = new ListNode(3); 
	// head->data = 2;
	head->next = second;  
	// second->data = 4; 
	second->next = third; 

	// third->data = 3;  
	// third->next = NULL; 
	LinkList l;
	ListNode *newList = l.addTwoNumbers(head, head);
	printList(newList);
}