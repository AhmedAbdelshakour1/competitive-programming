// https://leetcode.com/problems/linked-list-cycle/description/

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
    const int INF = 2e9;
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        while(head -> next != NULL){
            if(head -> next -> val == INF) return true;
            head -> next -> val = INF;
            head = head -> next;
        }
        return false;
    }
};

// Another Solution using Floyd’s slow and fast pointers approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) return true;
        }
        return false;
    }
};
