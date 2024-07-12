// Write a function to reverse a singly linked list.
// The function should take the head of the list and return the new head of the reversed list.

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;  // store next node
            current->next = prev;  // reverse the current node's pointer
            prev = current;        // move pointers one position ahead
            current = next;
        }

        return prev;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    // Clean up the memory
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
