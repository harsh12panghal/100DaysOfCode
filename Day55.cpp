/*
147. Insertion Sort List


Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element 
in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


*/



class Solution {
public:

    ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

    }
    return slow;

    }

    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        //merging the 2 sorted LL
        while(left!= NULL && right!=NULL){
            if(left->val < right->val){
                temp->next = left;
                temp = left;

                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;

                right = right->next;
            }
        }

        while(left != NULL){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right != NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }

        return ans->next;

    }

    ListNode* insertionSortList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    //break LL in 2 halfs after finding mid
    ListNode* mid = findMid(head);

    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = NULL;


    //recursion tp sort the 2 halves 
    left = insertionSortList(left);
    right = insertionSortList(right);

    //merge both halves 
    ListNode* ans = merge(left, right);

    return ans;
    }
};
