#include <bits/stdc++.h>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;

    // costructor
    ListNode(int value) : val(value), next(nullptr) {}
    
    // it is also a constructor both are same only syntax and styling is different
   
    // ListNode(int value){
    //     this -> val = value;
    //     this -> next = NULL;
    // }

};

ListNode* mergeSortedLists(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0); // Dummy head node to simplify handling edge cases
    ListNode* current = dummyHead; // Pointer to the current node in the merged list

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // Append any remaining nodes from l1 or l2 (if any)
    if (l1) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    ListNode* mergedList = dummyHead->next; // Get the merged list starting from the first node
    delete dummyHead; // Clean up the dummy head

    return mergedList;
}

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create two sorted linked lists
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    // Merge the two sorted linked lists
    ListNode* mergedList = mergeSortedLists(l1, l2);

    cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory (not shown in detail in this example)
    
    return 0;
}
