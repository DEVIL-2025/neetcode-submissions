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
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        if(head == NULL){
            ListNode* temp = new ListNode(val);
            head = temp;
            tail = temp;
        }
        else{
            ListNode* temp = new ListNode(val);
            tail -> next = temp;
            tail = temp;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        int carry = 0;
        while(curr1 != NULL || curr2 != NULL || carry > 0){
            int val1 = 0;
            if(curr1 != NULL)
                val1 = curr1 -> val;
            int val2 = 0;
            if(curr2 != NULL)
                val2 = curr2 -> val;
            
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(newHead, newTail, digit);
            if(curr1 != NULL)
                curr1 = curr1 -> next;
            if(curr2 != NULL)
                curr2 = curr2 -> next;
        }
        return newHead;
    }
};