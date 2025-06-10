/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        int n1 = 0;
        int n2 = 0;

        while(t1 != NULL){
            n1++;
            t1 = t1->next;
        }

        while(t2 != NULL){
            n2++;
            t2 = t2->next;
        }

        int diff = (n1>n2) ? (n1 - n2) : (n2-n1);
        t1 = headA;
        t2 = headB;

        if(n1 > n2){
            while(diff != 0){
                t1 = t1->next;
                diff--;
            }
        }
        else{
            while(diff != 0){
                t2 = t2->next;
                diff--;
            }
        }

        while(t1 != NULL || t2 != NULL){
            if(t1 == t2){
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
};