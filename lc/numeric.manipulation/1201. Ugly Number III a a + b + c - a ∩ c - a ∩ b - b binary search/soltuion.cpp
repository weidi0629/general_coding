/*
这题有好几个知识点，每个都不难，但要串在一起也不容易

首先看题设，就要想到 组合的公式 F(N) = a + b + c - a ∩ c - a ∩ b - b ∩ c + a ∩ b ∩ c

a 表示 能被 N 整除的个数，b c 也是一个意思 

a ∩ b？ 就是N能整除的 ab的 lcm 

a,c 的 lcm怎么求？  a*c/gcd(a,c)

那这个N怎么找，就要用到 binary search 了 

原始的帖子
https://leetcode.com/problems/ugly-number-iii/discuss/387539/cpp-Binary-Search-with-picture-and-Binary-Search-Template
*/


class Solution {
public:    
   int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(cnt < k) 
                lo = mid + 1;
            else
			   //the condition: F(N) >= k
                hi = mid;
        }
        return lo;
    }
};

