class Solution {
struct Node
{
    vector<Node*> next = vector<Node*>('z'-'a' + 1);
    bool val = false; // true for keys, false for non-key nodes
};

Node* put(Node* x, const string& key, int d)
{
    if(! x) 
        x = new Node;
    if(d == key.size())
    {
        x->val = true;
        return x;
    }
    char c = key.at(d); // Use dth key char to identify subtrie.
    x->next[c-'a'] = put(x->next[c-'a'], key, d+1);
    return x;
}

void searchTrie(Node* x, const string& key, int d, vector<int>& wordends)
{
    if(x)
    {
        if(x->val) 
            wordends.push_back(d);
        if(d < key.size())
        {
            char c = key.at(d);
            searchTrie(x->next[c-'a'], key, d+1, wordends);
        }
    }
}

public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        Node* root = nullptr;
        vector<vector<int>> res;
        // insert dictionary into trie
        for(const auto& w : words)
            root = put(root, w, 0); // 这里说明这个方程要是 recursive 的
        // search trie for substrings started with each letter of text
        for(int i = 0; i < text.size(); ++i) // 每个起点都找一次，因为每个起点可能有多个终点
        {
            vector<int> wordends;
            searchTrie(root, text.substr(i), 0, wordends);
            for(int we : wordends)
                res.push_back({i, i + we - 1});
        }
        return res;
    }
};
