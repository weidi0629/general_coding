/*
用rfind 来找，第二个参数表示在这个位或者这位之前找，变相的变成的beginwith方法

题目的算法是，按正常字符排序，排完之后，相邻的（之前的）才有可能是之后的那个的prefix，比起trie跟prefix tree要简单

*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        std::sort(folder.begin(), folder.end());
        string sign = "/",pre="dummy";
        for(auto f:folder){
            if(isBeginWith(f, pre))
                continue;
            res.push_back(f);
            pre = f + sign;
        }
        return res;
    }
    
private:
    bool isBeginWith(string s, string sub){
        if (s.rfind(sub,0) != string::npos)
            return true;
        return false;
    }
};
