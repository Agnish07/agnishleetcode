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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(temp != NULL){
            ListNode* front = head->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    }

    ListNode* findk(ListNode* head, int k){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL || cnt < k){
            temp = temp->next;
            cnt++;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode newhead = NULL;
        
        while(temp != NULL){
            find()
        }
    }
};