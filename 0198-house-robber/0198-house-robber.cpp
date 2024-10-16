class Solution {
public:
    int rob(vector<int>& nums) {
       vector<int>dp(nums.size()+1,-1);
       return robber(nums,nums.size()-1,dp);
    }
    int robber(vector<int>&arr,int i,vector<int>&dp){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int robbed=arr[i]+robber(arr,i-2,dp);
        int notrobbed=robber(arr,i-1,dp);
         return dp[i]=max(robbed,notrobbed);
    }
};