// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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

    int getLen(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    void skip(ListNode* &head, int n){
        for(int i = 0; i < n; i++){
            head = head->next;
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB) return headA;
        int lenA = getLen(headA);
        int lenB = getLen(headB);

        if(lenA > lenB){
            skip(headA, lenA - lenB);
        }else {
            skip(headB, lenB - lenA);
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
