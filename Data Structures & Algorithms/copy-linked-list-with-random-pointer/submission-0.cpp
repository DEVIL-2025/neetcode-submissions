/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        //create a linked list
        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp -> val);
            temp = temp -> next;
        }

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            Node* forward1 = originalNode -> next;
            Node* forward2 = cloneNode -> next;
            originalNode -> next = cloneNode;
            originalNode = forward1;
            cloneNode -> next = originalNode;
            cloneNode = forward2;
        }

        temp = head;
        while(temp != NULL){
            if(temp -> next != NULL){
                if(temp -> random != NULL){
                    temp -> next -> random = temp -> random -> next;
                }
            }
            temp = temp -> next -> next;
        }

        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            if(originalNode != NULL)
                cloneNode -> next = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};
