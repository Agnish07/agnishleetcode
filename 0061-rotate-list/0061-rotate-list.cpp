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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int n = 1;
        while(temp->next != NULL){
            temp = temp->next;
            n++;
        }

        
        k = k%n;
        if(k == 0) return head;

        temp->next = head;
        ListNode* curr = head;
        int steps = n-k-1;
        while(steps != 0){
            curr = curr->next;
            steps--;
        }

        ListNode* ans = curr->next;
        curr->next = NULL;

        return ans;
    }   
};