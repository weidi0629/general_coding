/*
max_freq
1. 其他都是 max_freq -1, 只有一种是max_freq
2. 都是一次 
3. 都是 max_freq, 多一个不知道什么玩意

我们能知道的参数， max_freq, 到目前为止几个 i, 每个freq的个数. 注意 freq是频率,这里的count是统计某个频率出现过多少次， 以此退出如下公式. 

1. (max_freq-1)*count[max_freq-1] + max_freq*1 = i // freq * count = total number 
2. max_freq = 1
3. max_freq*count[max_freq] +1 = i 

注意i是从0开始，真的编程时i要往前搞一个 

*/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> num_count,freq_count;
        int res = INT_MIN, max_freq = INT_MIN;
        for(int i=0; i<nums.size();i++){
            num_count[nums[i]]++;
            freq_count[num_count[nums[i]]-1]--;
            freq_count[num_count[nums[i]]]++; 
            max_freq = max(max_freq, count[nums[i]]);
            if(((max_freq-1)*freq_count[max_freq-1] + max_freq*1 ==i-1)||(max_freq = 1)||(max_freq*freq_count[max_freq] +1 == i-1 ))
                res = i+1;
            
        }
        return res;
    }
};
