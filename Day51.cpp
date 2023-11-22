/*
83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

*/



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        if(head == NULL)
            return NULL;

        while(curr != NULL){
            if((curr->next != NULL) && (curr->val == curr->next->val)){
                ListNode* next_next = curr->next->next;
                ListNode* toBeDeleted = curr->next;
                delete toBeDeleted;
                curr->next = next_next;
            
            }
            else{
                curr = curr->next;
            }

        }
        return head;
    }
};
