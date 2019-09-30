/*
You are given two strings s and t of the same length. You want to change s to t. Changing the i-th character of s to i-th character of 
t costs |s[i] - t[i]| that is, the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of twith a cost less 
than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.
*/

/*
这题自己想到了做一个新的成本的数组，但是答案更加简单，直接在制作的同时把sliding window搞出来了 

一般的直觉是要求一个max，但这题的特点可以不用求：
注意 j 一直在往前走，如果左边不合格，左边window往右移动一位，右边j也移动一位，所以之前的window size能一直保持住（答案只要求返回size就行）
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), i=0,j=0, k=0;
        for(j=0; j<n;j++){
            maxCost -= abs(t[j] -s[j]);
            if(maxCost<0)
                maxCost += abs(t[i]-s[i++]);
        }
        return j-i;
    }
};

