class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(256,0);
        vector<bool> seen(256,false);
        for(auto ch:s)
            cnt[ch]++;
        string res = "0";
        for(auto ch:s){
            cnt[ch]--; // 用掉了
            if(seen[ch] == true) continue;
            while(ch<res.back()&&cnt[res.back()]){ // 如果符合条件（新的比结果最后一个小，并且最后一个后面还有），就把最后一个炸了。
                seen[res.back()] = false;
                res.pop_back();
            }
            res += ch;
            seen[ch] = true;
        }
        return res.substr(1);
    }
};
