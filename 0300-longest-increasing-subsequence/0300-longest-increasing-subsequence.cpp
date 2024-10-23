class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        return LIS(nums,dp);
    }
    int LIS(vector<int>& nums,vector<int>& dp){
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],(dp[j]+1));
                }
            }
        }
        int ans=*max_element(dp.begin(),dp.end());
        return ans;
    }
};