/*
dp[i]: the min height for placing first books i - 1 on shelves
For dp[i+1],
either place book i on a new shelve => dp[i] + height[i],
or try to place book i on previous shelve => min(dp[j] + max(height[j+1] .. height[i])), where sum(width[j+1] + ... + sum(width[i]) <= shelve_width

this actually has another meaning: grab previous books on this level and move to next level together, utilizing the sub_problem dp[j]
*/

class Solution {
    public int minHeightShelves(int[][] books, int shelf_width) {
        int[] dp = new int[books.length + 1];
        
        dp[0] = 0;
        
        for (int i = 1; i <= books.length; ++i) {
            int width = books[i-1][0];
            int height = books[i-1][1];
            dp[i] = dp[i-1] + height;
            for (int j = i - 1; j > 0 && width + books[j-1][0] <= shelf_width; --j) {
                height = Math.max(height, books[j-1][1]);
                width += books[j-1][0];
                dp[i] = Math.min(dp[i], dp[j-1] + height);//看看能不能把他们一起移到下一层
            }
        }
        return dp[books.length];
    }
}
