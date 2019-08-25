/*
主要用prefix，如果遇到两个相同的prefix， 那么当中的就都不要，因为和肯定等于0. 
这题不用想交叉范围，窗口之类的东西，因为不是要你优化找最值。 就是顺序查找。先找到先处理，把当中所有的零时记录都删除。
如果找到第一次prefix记录的地点？ 用map

*/

ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        dummy->next = head;
        int prefix = 0;
        map<int, ListNode*> m;
        while (cur) {
            prefix += cur->val;
            if (m.count(prefix)) {
                cur =  m[prefix]->next;
                int p = prefix + cur->val;
                while (p != prefix) {
                    m.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                m[prefix]->next = cur->next;
            } else {
                m[prefix] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
