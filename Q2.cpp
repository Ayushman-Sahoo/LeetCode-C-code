/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

/* 
   Definition of a node in singly linked list 
*/
struct ListNode {
    int val;            // Stores single digit (0–9)
    ListNode* next;     // Pointer to next node

    // Constructor
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

/* 
   Function to add two numbers represented by linked lists 
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    // Dummy node (helps in building result list easily)
    ListNode* dummy = new ListNode(0);

    // Pointer to build the result list
    ListNode* current = dummy;

    int carry = 0;   // Stores carry during addition

    // Loop until both lists end AND no carry remains
    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;   // Start sum with carry

        // If l1 is not finished, add its value
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;   // Move l1 to next node
        }

        // If l2 is not finished, add its value
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;   // Move l2 to next node
        }

        // Create new node with digit part of sum
        current->next = new ListNode(sum % 10);

        // Move current pointer
        current = current->next;

        // Update carry
        carry = sum / 10;
    }

    // Return result list (skipping dummy node)
    return dummy->next;
}

/* 
   Function to print linked list 
*/
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* 
   MAIN FUNCTION 
*/
int main() {

    /*
      Creating first linked list: 2 -> 4 -> 3
      Represents number 342
    */
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    /*
      Creating second linked list: 5 -> 6 -> 4
      Represents number 465
    */
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Call function to add two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result linked list
    cout << "Result: ";
    printList(result);

    return 0;
}