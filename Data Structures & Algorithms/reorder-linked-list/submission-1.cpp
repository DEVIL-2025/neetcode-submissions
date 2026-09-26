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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    void reverse(ListNode* &head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }
    void reorderList(ListNode* head) {
        if(head -> next == NULL){
            return;
        }
        ListNode* curr1 = head;
        ListNode* mid = findMid(head);
        ListNode* curr2 = mid -> next;
        mid -> next = NULL;
        reverse(curr2);

        while(curr1 != NULL && curr2 != NULL){
            ListNode* forward1 = curr1 -> next;
            ListNode* forward2 = curr2 -> next;

            curr1 -> next = curr2;
            curr2 -> next = forward1;
            curr1 = forward1;
            curr2 = forward2;
        }

    }
};
