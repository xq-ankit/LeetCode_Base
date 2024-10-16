class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,0);
        dp[0]=0;
        dp[1]=cost[0];
         for(int i=2;i<=n;i++){
            int s=dp[i-1];
            int f=dp[i-2];
            dp[i]=min(s,f)+cost[i-1];
        }
        return min(dp[n],dp[n-1]);
    }
};