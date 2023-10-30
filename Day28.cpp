/*
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

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


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        int val = len - n;


        if(len <= 1){
            ListNode* temp = NULL;
            return temp;
        }

        if(len == n){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        
        else{
            ListNode* prev = NULL;
            ListNode* curr = head;
            int cnt = 1;
            while(cnt <= val){
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            prev->next = curr->next;
            curr->next = NULL;

            delete curr;

        }
        return head;
    }
};
