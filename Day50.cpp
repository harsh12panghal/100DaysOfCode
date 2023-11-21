/*
25. Reverse Nodes in k-Group


Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



*/


class Solution {
public:
    int getLength(ListNode* head){
        int cnt = 0;
        while(head != NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head ->next == NULL){
            return head;
        }
        int len = getLength(head);
        if(k > len)
            return head;

        ListNode* prev = NULL;
        ListNode* forward = NULL;
        ListNode* curr = head;
        int pos = 0;

        while(pos < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            pos++;
        }

        if(forward != NULL){
            head->next = reverseKGroup(forward, k);
        }

        return prev;

    }
};
