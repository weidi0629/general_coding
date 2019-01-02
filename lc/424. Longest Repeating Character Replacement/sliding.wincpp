class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0, maxlen=0, maxcount=0;
        int n=s.size();
        vector<int> count(26,0); //用这个来计数每个字符出现的次数
        for(int end=0; end<n; end++){
            maxcount = max(maxcount, ++count[s[end]]);
            //if((end-start-maxcount)>k){//乱七八糟的数超过k，要移动start 
            while((end-start+1-maxcount)>k){//注意这里是while，因为减掉之后不知道剩下是什么
                count[count[start]]--;
                start++;
            }
            maxlen=max(maxlen,end-start+1);
        }       
        return maxlen;
        
    }
};
