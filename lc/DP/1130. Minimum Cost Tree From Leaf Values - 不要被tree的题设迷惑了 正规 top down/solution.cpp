/*
这题首先应该想到DP公式。另外还有一种解法在vector processing中有详细解释 
*/

class Solution {
public:
    int memo[41][41]; // memo[i][j]: final answer between i to j
    int maxi[41][41]; // maxi[i][j]: max value between i to j 
    
    int dp(int left, int right){
        if(left == right) return 0;
        int ans = INT_MAX;
        if(memo[left][right] !=-1) return memo[left][right];
        for(int i=left; i<right; i++){
            ans = min(ans,maxi[left][i]*maxi[i][right] + dp(left,i)+dp(i+1,right));
        }
        memo[left][right] = ans;
        return ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n =arr.size();
        memset(memo,-1,sizeof(memo));
        for(int i=0; i<n; i++){
            maxi[i][i]=arr[i];
            for(int j=i+1; j<n; j++){
                maxi[i][j]=max(maxi[i][j],arr[j]); // simply get the max value 
            }
        }
        return dp(0,n-1);
    }
};
