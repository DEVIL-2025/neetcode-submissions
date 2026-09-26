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
    ListNode* findPrev(ListNode* head){
        if(head -> next == NULL){
            return head;
        }
        ListNode* prev = head;
        while(prev -> next -> next != NULL){
            prev = prev -> next;
        }
        return prev;
    }

    void solve(ListNode* &head, ListNode* &prev, ListNode* &tail){
        if (head == tail || head->next == tail)
            return;
            
        ListNode* forward = head -> next;
        head -> next = tail;
        tail -> next = forward;
        prev -> next = NULL;
        head = forward;
        tail = prev;
        prev = findPrev(head);
        solve(head, prev, tail);
    }
    void reorderList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = findPrev(head);
        ListNode* tail = prev -> next;

        solve(curr, prev, tail);
    }
};
