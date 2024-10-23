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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
         // Create two dummy nodes for two partitions
        ListNode lessHead(0); // Dummy head for "less than x" list
        ListNode greaterHead(0); // Dummy head for "greater than or equal to x" list
        
        // Pointers to build the two lists
        ListNode* lessPtr = &lessHead;
        ListNode* greaterPtr = &greaterHead;
        
        // Traverse the original list
        while (head) {
            if (head->val < x) {
                // Append to less list
                lessPtr->next = head;
                lessPtr = lessPtr->next;
            } else {
                // Append to greater list
                greaterPtr->next = head;
                greaterPtr = greaterPtr->next;
            }
            head = head->next; // Move to the next node
        }
        
        // Connect the end of the less list to the start of the greater list
        lessPtr->next = greaterHead.next;
        
        // End the greater list
        greaterPtr->next = nullptr;
        
        // Return the head of the combined list
        return lessHead.next;
    }
};