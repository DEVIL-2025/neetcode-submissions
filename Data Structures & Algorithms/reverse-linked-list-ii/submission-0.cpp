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
    ListNode* reverse(ListNode* &head, ListNode* &tail) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        ListNode* stop = tail->next;  

        while (curr != stop) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;

        ListNode* left1 = head;
        int cnt = 1;
        while(cnt < left){
            left1 = left1 -> next;
            cnt++;
        }

        ListNode* right1 = head;
        cnt = 1;
        while(cnt < right){
            right1 = right1 -> next;
            cnt++;
        }

        ListNode* before = NULL;
        if(left > 1){
            before = head;
            cnt = 1;
            while(cnt < left - 1){
                before = before -> next;
                cnt++;
            }
        }

        ListNode* after = right1 -> next;
        ListNode* reversed = reverse(left1, right1); 

        if(before != NULL)
            before -> next = reversed;
        else
            head = reversed;

        left1 -> next = after;

        return head;
        
    }
};