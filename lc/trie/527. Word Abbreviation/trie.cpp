/*
  1. 没有定义正规的add, search 方程，直接在内部遍历trie了
  2. 注意 make_shared的用法 
*/
struct Trie {
    shared_ptr<Trie> child[26];
    int count{0};   
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, vector<int>> group;
        vector<int> prev(dict.size(), 1); // use single char as prefix by default
        for (int i = 0; i < dict.size(); ++i) {
            auto abbr = abbrev(dict[i], prev[i]);
            group[abbr].push_back(i);
        }
        
        vector<string> result(dict.size());
        for (auto &p:group) { // & 还是means ref 
            auto trie = make_shared<Trie>();
            for (int i:p.second) {  // i is index 
                auto ptr = trie;
                for (char c:dict[i]) {
                    if (ptr->child[c-'a'] == nullptr) ptr->child[c-'a'] = make_shared<Trie>();
                    ptr = ptr->child[c-'a'];
                    ++ptr->count;
                }
            }
            for (int i:p.second) {
                auto ptr = trie;
                int prefix = 1;
                for (char c:dict[i]) {
                    if (ptr->child[c-'a']->count == 1) break;
                    ptr = ptr->child[c-'a'];
                    ++prefix;
                }
                result[i] = abbrev(dict[i], prefix);
            }
        }
        return result;
    }
    
    
    string abbrev(string &str, int k) { // k is length of prefix
        if (str.size() - k <= 2) {
            return str;
        }
        return str.substr(0, k) + to_string(str.size()-k-1) + str.back();
    }
};
