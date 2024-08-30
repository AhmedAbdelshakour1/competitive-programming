// https://leetcode.com/problems/add-two-numbers-ii/description/

class Solution {
public:
    int length(ListNode* l){
        int cnt = 0;
        while(l){
            cnt++;
            l = l->next;
        }
        return cnt;
    }

    ListNode* pad(ListNode* l, int count){
        ListNode* head = l;
        for(int i = 0; i < count; i++){
            head = insertFront(head, 0);
        }
        return head;
    }
    ListNode* insertFront(ListNode* head, int target){
        ListNode* node = new ListNode(target);
        if(head) node->next = head;
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int &carry) {
        if(l1 == nullptr && l2 == nullptr && carry == 0) return nullptr;

        ListNode* sum = addTwoNumbers(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, carry);
        int value = carry + (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val);
        carry = value / 10;
        return insertFront(sum, value % 10);

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        if(len1 < len2) l1 = pad(l1, len2 - len1);
        else if(len1 > len2) l2 = pad(l2, len1 - len2);
        int carry = 0;
        ListNode* ans = addTwoNumbers(l1, l2, carry);
        if(carry) ans = insertFront(ans, carry);
        return ans;
    }
};
