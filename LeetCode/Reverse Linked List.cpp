// https://leetcode.com/problems/reverse-linked-list/description/

// iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head != nullptr){
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};

// recursive solution

class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
        if(head == nullptr) return prev;

        ListNode* nxt = head->next;
        head->next = prev;
        return reverseList(nxt, head);
    }
};
