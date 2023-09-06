// https://leetcode.com/problems/split-linked-list-in-parts/description/

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int sz = 0;
        ListNode* curr = head;
        while(curr){
            sz++;
            curr = curr -> next;
        }

        int n = sz / k, rem = sz % k;
        curr = head;
        ListNode* prev;
        for(int i = 0; i < k && curr; i++, rem--){
            ans[i] = curr;
            for(int j = 0; j < n + (rem > 0); j++){
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = nullptr;
        }
        return ans;
    }
};
