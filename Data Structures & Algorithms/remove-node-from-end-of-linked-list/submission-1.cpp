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
    int countNode(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head -> next == NULL){
            return NULL;
        }

        int count = countNode(head);
        int pos = count - n + 1;
        int cnt = 0;
        ListNode* temp = head;
        if(pos == 1){
            head = head -> next;
            delete temp;
            return head;
        }
        while(cnt < pos - 2){
            cnt++;
            temp = temp -> next;
        }
        ListNode* curr = temp -> next;
        temp -> next = curr -> next;
        delete curr;
        return head;
    }
};
