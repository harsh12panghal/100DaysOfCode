/*
2. Add Two Numbers




You are given two non-empty linked lists representing two non-negative integers. The digits are 
stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.




*/

class Solution {
public:
    void insertAtTail(ListNode* &head, ListNode* &tail, int digit){
        ListNode* temp = new ListNode(digit);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
            return;
        }
    }

    ListNode* solve( ListNode* first,  ListNode* second){
        int carry = 0;
        
         ListNode* ansHead = NULL;
         ListNode* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL)
                val1 = first->val;
            int val2 = 0;
            if(second != NULL)
                val2 = second->val;

            int sum = carry + val1 + val2;
            int digit = sum%10;
            carry = sum/10;

            insertAtTail(ansHead, ansTail, digit);

            if(first != NULL)
                first = first->next;
            
            if(second != NULL)
                second = second->next;
        }
        return ansHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = solve(l1, l2);
        
        return ans;
        
            
        
    }
};
