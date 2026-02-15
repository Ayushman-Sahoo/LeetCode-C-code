#include <iostream>
using namespace std;

// Definition of Node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void push_back(ListNode*& head, ListNode*& tail, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
} 

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true; // A single node or empty list is a palindrome
    }

    // Step 1: Find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    ListNode* prev = NULL;
    ListNode* curr = slow;
    while (curr != NULL) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    // Step 3: Compare the first half and the reversed second half
    ListNode* firstHalf = head;
    ListNode* secondHalf = prev; // 'prev' is now the head of the reversed second half
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true; // It's a palindrome
}

// Main function
int main() {

    ListNode* head = NULL;
    ListNode* tail = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        push_back(head, tail, value);
    }

    cout << "Linked List: ";
    display(head);

    if (isPalindrome(head))
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}