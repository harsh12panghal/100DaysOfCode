/*

Sort linked list of 0s 1s 2s



*/

void insertAtTail(Node* &tail, Node* curr){
    tail->next = curr;
    tail = curr;
}


Node* sortList(Node *head){

    Node* zeroHead = new Node(-1);
    Node* zerotail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* onetail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twotail = twoHead;

    Node* curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            insertAtTail(zerotail, curr);
        }
        else if(curr->data == 1){
            insertAtTail(onetail, curr);
        }
        else if(curr->data == 2){
            insertAtTail(twotail, curr);
        }
        curr = curr->next;
    }
    
    if(oneHead != NULL){
        zerotail->next = oneHead ->next;
        onetail->next = twoHead->next;
        twotail->next = NULL;
    }
    else{
        zerotail->next = twoHead->next;
        twotail->next = NULL;
    }

    return zeroHead->next;
    




}
