class Solution {
public:
    unordered_map<Node*,Node*> mp;
    
    Node* copyRandomList(Node* head){
        if(!head) return NULL;
        if(mp[head] !=NULL) return mp[head];
        Node* copyNode = new Node(head->val);
        mp[head] = copyNode;
        mp[head]->next = copyRandomList(head->next);
        mp[head]->random = copyRandomList(head->random);
        return copyNode;
    }
};
