class StreamChecker {
public:
    struct TrieNode{ /*Tri树节点*/
        bool isend;
        TrieNode* next[26];
        TrieNode(){
            isend = false;
            for(int i =0; i< 26; i++)
                next[i] = nullptr;
        }
        ~TrieNode() {
            for (auto n : next)
                delete n;
        }
    };
    
    TrieNode* root = new TrieNode();  /*Tri树初始化*/
    string buf; /*用来存储流数据*/
    
    void insert(string word){ /*Tri树  倒过来 插入单词*/
        auto ptr = root;
        for(int i=0;i<word.size();i++){
            char ch = word[word.size()-1-i];
            if(ptr->next[ch-'a'] == nullptr){
                ptr->next[ch-'a'] = new TrieNode();
            }
            ptr = ptr->next[ch-'a'];
        }
        ptr->isend = true;
    }

    StreamChecker(vector<string>& words) {
        for(auto word: words){
            insert(word);
        }
    }
    
    bool query(char letter) {
        buf.insert(buf.begin(),letter);
        auto ptr = root;
        for(char ch: buf){
            ptr = ptr->next[ch - 'a'];
            if(ptr == nullptr){
                return false;
            }
            if(ptr->isend == true){
                return true;
            }
        }
        return false;
    }
};
