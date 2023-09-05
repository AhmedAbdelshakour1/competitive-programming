// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* curr = head;
        unordered_map<Node*, Node*> mp;

        while(curr){
            mp[curr] = new Node(curr -> val);
            curr = curr -> next;
        }
        curr = head;
        while(curr){
            mp[curr] -> next = mp[curr -> next];
            mp[curr] -> random = mp[curr -> random];
            curr = curr -> next;
        }
        return mp[head];
    }
};

// Another Solution with Space Complexity: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* curr = head;

        while(curr){
            Node* new_node = new Node(curr -> val);
            new_node -> next = curr -> next;
            curr -> next = new_node;
            curr = new_node -> next;
        }
        curr = head;
        while(curr){
            curr -> next -> random = curr -> random ? curr -> random -> next : nullptr;
            curr = curr -> next -> next;
        }
        curr = head;
        Node* new_head = curr -> next;
        Node* nxt;
        while(curr){
            nxt = curr -> next -> next;
            curr -> next -> next = curr -> next -> next ? curr -> next -> next -> next : nullptr;
            curr -> next = nxt;
            curr = curr -> next;
        }
        return new_head;
    }
};
