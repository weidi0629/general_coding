/*
如果序列S的总和小于等于0，我们只需要关心两个S即可，后面的都没用：加上一个S总和就会减少一点。
此时答案就是两个序列S拼接后的最优答案（经典的最大连续子序列）。

而序列S的总和大于0时，则中间所有的序列S都需要加上去。
而两头的序列，则需要取前缀和后缀的最大值。

*/

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long oneSum = 0;
        for(auto v: arr){
            oneSum += v;
        }
        long long ans = 0;
        int len = arr.size();
        
        // left + allMid + right
        if(oneSum > 0 && k >= 2){
            long long leftAns = 0;
            long long rightAns = 0;
            
            long long tmpAns = 0;
            for(int i=0;i<len;i++){
                tmpAns += arr[i];
                leftAns = max(leftAns, tmpAns);
            }
            
            tmpAns = 0;
            for(int i=len-1;i>=0;i--){
                tmpAns += arr[i];
                rightAns = max(rightAns, tmpAns);
            }
            
            ans = max(ans, leftAns + rightAns + (k-2) * oneSum);
        }
        
        //left + right
        if(k > 1){ // 针对只要求重复一次的情况
            for(int i=0;i<len;i++){
                arr.push_back(arr[i]);
            }
        }
        
        long long tmpAns = 0;
        for(auto v: arr){
            tmpAns += v;
            ans = max(ans, tmpAns);
            if(tmpAns < 0){
                tmpAns = 0;
            }
        }
        
        long long mod = 1000000007;
        return ans%mod;
    }
};
