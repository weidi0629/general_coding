int lastStoneWeightII(vector<int> A) {
        bitset<1501> dp = {1};
        int sumA = 0, res = 100;
        for (int a : A) {
            sumA += a;
            for (int i = sumA; i >= a; --i)
                dp[i] = dp[i] + dp[i - a]; // 这个相加并不会进位，跟或是一样的意思
        }
        for (int i = sumA / 2; i > 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;
    }
