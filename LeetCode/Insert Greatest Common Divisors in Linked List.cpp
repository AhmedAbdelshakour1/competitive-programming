// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* a = head;
        if(head->next == nullptr) return head;
        ListNode* b = a->next;
        while(b){
            ListNode* c = new ListNode(__gcd(a->val, b->val), b);
            a->next = c;
            a = b;
            b = b->next;
        }
        return head;
    }
};
