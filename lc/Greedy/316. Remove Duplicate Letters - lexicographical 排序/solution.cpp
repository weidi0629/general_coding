/*
每一个进来，如果比之前那个（位置）小，只要前面的值后面还有，就可以不要了。以为要lexi排序。这是greedy体现的地方.
*/

/*
非recursive的方法

只要进来的比后面那个小，就把前面那个踢掉。建立一个seen的set，如果之前来过了，后面就不要处理，直接continue(也是lexi排序的原因)。
但每次进来，cnt的次数都要少一次。说明用掉了 
*/

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


/*
recursive version
两条路径
1. 找最小的，只要有比之前小的，并且之前那个还有的，就往前走，找到这个pos
2. 等某一个值用完了，那之前那个最小的就是新的开始的点，把最小的这个char都去掉. 

所以总的想法就是找到每次递归保证找到这个最小的点。

---|————————————|——————————
   min         used up
*/

public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] cnt = new int[26];
        int pos = 0; // the position for the smallest s[i]
        for (int i = 0; i < s.length(); i++) cnt[s.charAt(i) - 'a']++;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(pos)) pos = i;
            if (--cnt[s.charAt(i) - 'a'] == 0) break;
        }
        return s.length() == 0 ? "" : s.charAt(pos) + removeDuplicateLetters(s.substring(pos + 1).replaceAll("" + s.charAt(pos), ""));
    }
}

