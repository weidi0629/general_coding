/*
  这题最关键是：倒过来建数，正过来搜索.
  代码没有debug过，但是算法得了解。
  源代码：
  https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure
  用map的方法还没有仔细看：
  https://leetcode.com/problems/palindrome-pairs/discuss/79199/150-ms-45-lines-JAVA-solution
*/

class Solution {
private: 
    static class TrieNode{
        vector<TrieNode> next;
        int index;
        vector<int> list;
        
        TrieNode(){
            next = vector<TrieNode>(26,nullptr);
            index =-1;
        }     
    }
    
public:
    vector<vector<int>> res;
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        TreeNode root = new TreeNode();
        for(int i=0; i< words.size(); i++){
            addnode(root,words[i],i);
        }
        
        for(int i=0; i< words.size(); i++){
            search(root,words,i);
        }
        
        return res;
        
    }
    
    /*
        要到过来建数
    */
    void addnode(TreeNode* root,string word, int index){ 
        for(int i=word.size(); i>=0; i++){
            if(root.next[word[i]]!=nullptr)
                root.next[word[i]] = new TreeNode();
            
            if(ispal(word,0,i-1))
                root.list.push_back(index); //1.这里是用在正过来找时，找的那个word结束了。如果正好停在这个点，因为能找到这里，说明前面已经是palindrome, 之后又是从这里判断是paldrome，那把找的这append在后面就行了. 这个情况是，正找的那个，比现在这个word短
            root = root.next[word[i]];
        }
        //2.这个点建完了。这个情况适用在找的那个，比这个长。但是还得在找的时候判断，正找的那个剩下的是不是paldrome
        root.index = index;
        root.list.push_back(index); 
        
    }
    
    void search(TreeNode root, vector<string>& words, int i){
        for(int j=0; j<words[i].size(); j++){//这里要正过来找
            if(root.index>=0 && root.index!=i &&root.list!=null){//正在找的这个比找到这个长，是上面add中的第二个情况。现在要判断剩下的是不是paldrome
                if(ispal(words[i],j,words[i].size()))
                    for(auto idx:root.list)
                        res.push({i,idx});
                
                if(root.next[words[i][j]]!=nullptr)
                    return; //这一轮找不到了
                root = root.next[words[i][j]];
            }   
        }
        
        for(auto idx:root.list) //正在找的比找到的这个短，是上面的第一种情况。因为找到的list里已经包装身下的都是paldrome了，所以可以如上所说，把正在找的append后面即可。
            res.push({i,idx});   
    }
    
    bool isPal(string word, int i, int j){
        while(i<j){
            if(word[i]!=word[j]) return false;
            i++;j--;
        }
        return true;
    }
    
};
