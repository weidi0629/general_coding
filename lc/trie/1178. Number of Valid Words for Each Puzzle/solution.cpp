/*
这题用bit来解更方便一些，但trie的方法是个很好的练习。
用所有的words来建立一个trie tree 
每个puzzlel来traverse这个tree
每个puzzle 从index开始到最后一位，只要有个branch可以走就（考虑某个branch很短，who cares,只要能走到底就行）
*/

class Solution {
    struct TrieNode{
        int countEnd;
        TrieNode* children[26]; // 已经知道数量，直接用数组
        TrieNode() {
            countEnd = 0;
            memset(children, 0, sizeof(TreeNode*)*26); //处理内存的方法
        }
    };
    TrieNode trie; // 注意总得不是一个指针，是一个真的node
    
    void insert(int countChar[26]) { // 注意它的insert，根据题意输入了一个数组
        TrieNode * currNode = & trie; // 都是从总得开始，注意赋值的方法 
        for (int i = 0; i < 26; i++) {
            if (countChar[i] == 1) {
                if (currNode->children[i] == nullptr)
                    currNode->children[i] = new TrieNode();
                currNode = currNode->children[i];
            }
        }
        currNode->countEnd ++; // 在这一位有几个结束
    }
    
    void buildTrie(vector<string> & words) {
        int countChar[26];
        for (int i = 0; i < words.size(); i++) {
            memset(countChar, 0, sizeof(int)*26);
            string & w = words[i]; // 注意赋值的方法
            for (auto c: w) { countChar[c-'a'] = 1; } //只要有就附一
            int count = 0;
            for (int i = 0; i < 26; i++) { count += countChar[i]; }
            if (count > 7) continue; // 大于7不要，这是根据题意来的
            insert(countChar);
        }
    }
	
	int search(TrieNode* node, string & p, int idx, char firstChar, bool metFirst) {
        int res = 0;
        if (node->countEnd > 0 && metFirst) { // 第一个要包含，这是根据题意。考虑如果有个很短的branch，已经到最后一个，依然没有找到第一个char，
        //那这个就不要了
            res += node->countEnd;
        }
        for (int i = idx; i < p.length(); i++) { //只要有能走的branch都可以
            if (node->children[p[i]-'a'] != nullptr) {
                res += search(node->children[p[i]-'a'], p, i+1, firstChar, metFirst || (p[i] == firstChar));
            }
        }
        return res;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        buildTrie(words);
        vector<int> res;
        for (int i = 0; i < puzzles.size(); i++) {
            char firstChar = puzzles[i][0];
            sort(puzzles[i].begin(), puzzles[i].end()); // 需要sort，否则traverse顺序就不对了 
            int cnt = search(&trie, puzzles[i], 0, firstChar, false);
            res.push_back(cnt);
        }
        return res;
    }
};
