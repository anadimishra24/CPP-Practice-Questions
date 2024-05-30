#include <bits/stdc++.h>
using namespace std;


/* Add two number */
class ListNode{
public:
    int data;
    ListNode *next = NULL;
};

// print the LL
void printList(ListNode* node){
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL";
}

// add the element at the end
void append(struct ListNode** head, int node_data){

    /* 1. create and allocate ListNode */
    struct ListNode* newNode = new ListNode;
    
    struct ListNode *last = *head; /* used in step 5*/
    
    newNode->data = node_data;
    newNode->next = NULL;
    
    if (*head == NULL){
        *head = newNode;
        return;
    }
    
    while (last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
    return;
}

// reverse the original linked list
void reverseLL(ListNode* &head){
    ListNode* temp = head;
    ListNode* nextList = NULL;
    ListNode* prev = NULL;

    while(temp != NULL){
        nextList = temp -> next;
        temp -> next = prev;

        // move the prev and temp
        prev = temp;
        temp = nextList;
    }
    head = prev;
}

// reverse the LL and get the copy
ListNode* reverseLLcopy(ListNode* head){
    ListNode* prev = NULL;
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // printList(prev);
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    ListNode* ans = NULL;
    ListNode* head = ans;
    int digit = 0, sum = 0, carry = 0;

    while(l1 && l2){
        sum = carry + (l1 -> data + l2 -> data);
        cout << "Sum = " << sum << endl;
        digit = (sum % 10);
        carry = sum / 10;
        append(&ans, digit);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    while(l1){
        sum = carry + (l1 -> data);
        cout << "Sum = " << sum << endl;
        digit = (sum % 10);
        carry = sum / 10;
        append(&ans, digit);
        l1 = l1 -> next;
    }

    while(l2){
        sum = carry + (l2 -> data);
        cout << "Sum = " << sum << endl;
        digit = (sum % 10);
        carry = sum / 10;
        append(&ans, digit);
        l2 = l2 -> next;
    }

    if(carry != 0){
        append(&ans, carry);
    }

    //reverseLL(ans);
    printList(ans);
    return ans;
}
/* End of add two number*/

// merge two sorted array
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

/*optimized approach for sapce and time..

    // Create a dummy node to form the starting point of the new list
    ListNode dummy;
    ListNode* tail = &dummy; // This will be the last node in the new list
    
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // At the end of the loop, at least one of list1 or list2 is NULL.
    // Connect the remaining part of the non-null list to our new list.
    if (list1) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // The new list starts at dummy.next
    return dummy.next;
} 
    */

    ListNode* tmp1 = list1;
    ListNode* tmp2 = list2;
    ListNode* newList = NULL;
    int val = 0;

    while(tmp1 && tmp2){
        if(tmp1 -> data <= tmp2-> data){
            val = tmp1 -> data;
            append(&newList,val);
            tmp1 = tmp1 -> next;
        }else{
            val = tmp2 -> data;
            append(&newList,val);
            tmp2 = tmp2 -> next;
        }
    }
    while(tmp1){
        val = tmp1 -> data;
        append(&newList,val);
        tmp1 = tmp1 -> next;
    }
    while(tmp2){
        val = tmp2 -> data;
        append(&newList,val);
        tmp2 = tmp2 -> next;
    }
    return newList;

}

// delete the middle of LL
ListNode* deleteMiddle(ListNode* head) {
    
    /* 1. approach using two pointer */

    if (head == nullptr || head->next == nullptr) {
        // If there's only one node or no node, delete and return nullptr
        delete head;
        return nullptr;
    }
    if (head->next->next == nullptr) {
        // If there are exactly two nodes, delete the second node
        delete head->next;
        head->next = nullptr;
        return head;
    }

    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = nullptr;

    // Fast pointer moves twice as fast as the slow pointer
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Slow now points to the middle node, prev points to the node before it
    if (prev != nullptr) {
        prev->next = slow->next;  // Unlink the middle node
    }
    cout << "Deleting node with value = " << slow->data << endl;
    delete slow;  // Delete the middle node

    return head;  
    
   
   /* 2. approach using  indexing 

    // get the len of LL
    ListNode *tmp = head;
    int size = 0;
    while(tmp != NULL){
        size++;
        tmp = tmp -> next;
    }

    int mid = size / 2;
    ListNode *prev = NULL;
    ListNode *list = head;
    while(mid != 0){
        prev = list; 
        list = list -> next;
        mid--;
    }

    prev -> next = list -> next;
    delete list;
    
    return head;
    */

}

// arrange LL in even - odd - even .. order
ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;  // Check for empty input
    
    ListNode odd;  // Dummy node to simplify edge cases for odd list
    ListNode* o_tail = &odd;
    ListNode even;  // Dummy node to simplify edge cases for even list
    ListNode* e_tail = &even;

    ListNode* tmp = head;
    while (tmp) {
        if (tmp->data % 2 == 0) {  // Even data, including 1 based on your condition to treat 1 as even
            e_tail->next = tmp;
            e_tail = e_tail->next;
        } else {  // Odd data
            o_tail->next = tmp;
            o_tail = o_tail->next;
        }
        tmp = tmp->next;
    }

    // Terminate both lists to avoid potential loops
    o_tail->next = NULL;
    e_tail->next = NULL;

    // Connect even list's end to odd list's start
    e_tail->next = odd.next;

    return even.next;  // Return the head of the even list which is now followed by the odd list
}

// twin max sum
int pairSum(ListNode* head) {
    
    if (!head) return 0;

    // get the middle of LL
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of LL
    ListNode* secondHalf = reverseLLcopy(slow);
    ListNode* firstHalf = head;

    int maxTwinSum = 0;
    while (secondHalf) {
        int currentSum = firstHalf->data + secondHalf->data;
        maxTwinSum = max(maxTwinSum, currentSum);
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return maxTwinSum;
}

// remove duplicates
ListNode* removeElements(ListNode* head, int val) {
    // Handle case where the list is empty
    if(head == NULL){
        return NULL;
    }

    ListNode* prev = NULL;
    ListNode* tmp = head;

    // Remove nodes with the specified value
    while (tmp != NULL){
        if(tmp->data == val){
            if (prev != NULL) {
                prev->next = tmp->next;
                delete tmp;
                tmp = prev->next;
            } else {
                // Update head if the first node has the value
                head = tmp->next;
                delete tmp;
                tmp = head;
            }
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    return head;        
}


int main(){


/* Add two number with LL
    ListNode *node = NULL;
    ListNode *head = node;

    ListNode *node1 = NULL;
    ListNode *head1 = node1;
    append(&head, 3);
    append(&head, 7);
    
    
    printList(head);
    cout << "\n";
    append(&head1, 9);
    append(&head1, 2);
    

    printList(head1);
    
    ListNode *ans = addTwoNumbers(head, head1);
    cout << "\nans = ";
    printList(ans);
*/

/* merge two sorted LL

    ListNode *node = NULL;
    ListNode *head = node;

    ListNode *node1 = NULL;
    ListNode *head1 = node1;

    append(&head, 1);
    append(&head, 2);
    append(&head, 4);
    
    printList(head);

    std::cout << "\n";

    append(&head1, 1);
    append(&head1, 3);
    append(&head1, 4);
    

    printList(head1);
    
    ListNode *ans =  mergeTwoLists(head, head1);
    std::cout << "\nans = ";
    printList(ans);
    */
     
/* delete the middle of LL
    ListNode *node = NULL;
    ListNode *head = node;

    append(&head, 2);
    append(&head, 1);
    append(&head, 3);
    append(&head, 5);
    append(&head, 6);
    append(&head, 4);
    append(&head, 7);
    
    printList(head);

    ListNode* ans =  deleteMiddle(head);
    cout <<"\nLL after delete middle: " << endl;
    printList(ans);
*/

/* twin sum

    ListNode *node = NULL;
    ListNode *head = node;

    append(&head, 5);
    append(&head, 4);
    append(&head, 2);
    append(&head, 1);
    
    // printList(head);

    int ans =  pairSum(head);
    cout <<"\npair sum =  " << ans << endl;
*/  


/* Remove duplicate elements*/

    ListNode *node = NULL;
    ListNode *head = node;

    append(&head, 1);
    append(&head, 2);
    append(&head, 6);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);
    
    printList(head);

    int val = 6;
    ListNode* ans = removeElements(head, val);

    printList(ans);

    /*
    for (auto count: ans){
        cout << count << " ";
    }*/
    return 0;

}
