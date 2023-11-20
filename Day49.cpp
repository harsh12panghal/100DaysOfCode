/*
1290. Convert Binary Number in a Linked List to Integer

Given head which is a reference node to a singly-linked list. The value of each node in the linked 
list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
*/


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = -1;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }

        if(head == NULL){
            return 0;
        }
        if( head->next == NULL){
            return head->val;
        }
        int sum = 0;
        while(head != NULL){
            
            int value = head->val;
            sum += (value * pow(2, len));
            head = head->next;
            len--;
        }

        return sum;
    }
};
