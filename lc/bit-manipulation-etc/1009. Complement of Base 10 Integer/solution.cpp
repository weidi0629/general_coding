/*
无论什么数，跟他位数相等的，都是1的数，跟原来的数异或以下，就可以找到补集
*/

class Solution {
public:
    int bitwiseComplement(int N) {
        int mask =1;
        while(mask<N) mask |= mask<<1;
        return mask^N;
    }
};
