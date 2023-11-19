/*
19. Remove Nth Node From End of List



Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

*/


class Solution {
public:
    int getLength(ListNode* &head){
        ListNode* temp = head;
        int len = 1;
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int length = getLength(head);
        int pos = length - n;

        if(length <= 1){
            ListNode* temp = NULL;
            return temp;
        }
        if(length == n){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        else{
            ListNode* curr = head;
            ListNode* prev = NULL;
            int cnt = 1;

            while(cnt <= pos){
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
