struct Trie {
    vector<int> words;  // 数组记录这个点是属于那些字的
    vector<Trie *> children;
    Trie() {
        children = vector<Trie *>(26, nullptr); //注意它除了数组并没有其他参数
    }
    // Thanks to @huahualeetcode for adding this in case of memory leak
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    
    // member function, 所以不需要trie node在parameter里
    void add(const string &word, size_t begin, int index) { 
        words.push_back(index);
        if (begin < word.length()) {
            if (!children[word[begin] - 'a']) {
                children[word[begin] - 'a'] = new Trie();
            }
            children[word[begin] - 'a']->add(word, begin + 1, index); //children[word[begin] - 'a']就是一个node
        }
    }
    
    vector<int> find(const string &prefix, size_t begin) {
        if (begin == prefix.length()) {
            return words;
        } else {
            if (!children[prefix[begin] - 'a']) {
                return {};
            } else {
                return children[prefix[begin] - 'a']->find(prefix, begin + 1);
            }
        }
    }
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        forwardTrie = new Trie();
        backwardTrie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            forwardTrie->add(word, 0, i);
            reverse(word.begin(), word.end()); //注意这个原地reverse的功能
            backwardTrie->add(word, 0, i);
        }
    }
    
    int f(string prefix, string suffix) {
        auto forwardMatch = forwardTrie->find(prefix, 0);//返回的是最后这个点隶属过的string的index
        reverse(suffix.begin(), suffix.end());
        auto backwardMatch = backwardTrie->find(suffix, 0);
        // search from the back
        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin(); //从后面开始，因为位置也是weight
        while (fIter != forwardMatch.rend() && bIter != backwardMatch.rend()) {
            if (*fIter == *bIter) {
                return *fIter;
            } else if (*fIter > *bIter) {
                fIter ++;
            } else {
                bIter ++;
            }
        }
        return -1;
    }
    
private:
    Trie *forwardTrie, *backwardTrie;
};
