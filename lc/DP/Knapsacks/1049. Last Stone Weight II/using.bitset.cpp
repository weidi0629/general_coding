/*
In this solution, I use dp to record the achievable sum of the smaller group.
dp[x] = 1 means the sum x is possible.
*/

int lastStoneWeightII(vector<int> A) {
        bitset<1501> dp = {1};  // 0是肯定可以的
        int sumA = 0, res = 100;
        for (int a : A) {
            sumA += a;
            for (int i = sumA; i >= a; --i)
                dp[i] = dp[i] + dp[i - a]; // 这个相加并不会进位，跟或是一样的意思. dp[i]要么本身进行，或者[i-a]可以，那加上a也可以
        }
        for (int i = sumA / 2; i > 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;
    }
