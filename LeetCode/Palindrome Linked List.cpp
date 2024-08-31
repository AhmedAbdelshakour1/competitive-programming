// https://leetcode.com/problems/palindrome-linked-list/description/

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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head; ListNode* slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* prev = nullptr; ListNode* tmp = nullptr;

        while(slow){
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        ListNode* st = head; ListNode* end = prev;
        while(end){
            if(st->val != end->val) return false;
            st = st->next;
            end = end->next;
        }
        return true;
    }
};
