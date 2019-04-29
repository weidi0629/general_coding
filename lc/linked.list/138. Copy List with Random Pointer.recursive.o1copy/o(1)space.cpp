class Solution {
public: 
    Node* copyRandomList(Node* head){
        Node* cur= head, *cp = nullptr, *cp_head = nullptr; // cp是工作指针
        if(head == nullptr) return nullptr;
        while(cur != nullptr){  
            cp = new Node(cur->val); //编织时每个都要是新的 
            cp->next = cur->next;
            cur->next = cp;
            cur = cp->next;
        }
        cur = head;
        while(cur != nullptr){
            cp = cur->next; // 两个工作指针先就位
            if(cur->random != nullptr)
                cp->random = cur->random->next;
            cur = cp->next;
        }
        cp_head = head->next;
        cur = head;
        while(cur != nullptr){
            cp = cur->next;
            cur->next = cp->next;
            cur = cur->next;
            if(cur)
                cp->next = cur->next;
        }
        return cp_head;
    }
};
