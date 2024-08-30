// https://leetcode.com/problems/add-two-numbers/description/

// iterative solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr; ListNode* l3 = nullptr;
        int carry = 0;
        while(l1 || l2 || carry){
            int value = carry;
            if(l1) value += l1->val;
            if(l2) value += l2->val;
            ListNode* curr = new ListNode(value % 10);
            carry = value / 10;
            if(ans == nullptr) ans = curr;
            else l3->next = curr;
            l3 = curr;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return ans;
    }
};

// recursive solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry){
        if(l1 == nullptr && l2 == nullptr && carry == 0) return nullptr;
        ListNode* ans = new ListNode();
        int x = carry;
        x += l1 == nullptr ? 0 : l1->val;
        x += l2 == nullptr ? 0 : l2->val;
        ans->val = x % 10;
        ListNode* nxt = addTwoNumbers(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, x / 10);
        ans->next = nxt;
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }
};
