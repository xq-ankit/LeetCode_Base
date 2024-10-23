class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        return LIS(nums,dp);
        return LISusingBinarySearch(nums,dp);
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


    int LISusingBinarySearch(vector<int>& nums,vector<int>& dp){
        dp[0]=nums[0];
        int len=1;
        for(int i=1;i<dp.size();i++){
            if(nums[i]>dp[len-1]){
                dp[len]=nums[i];
                len++;
            }
            else{
            int idx=*lower_bound(dp.begin(),dp.begin() + len,nums[i]);
            // int idx=BinarySearch(dp,0,len-1,nums[i]);
            dp[idx]=nums[i];
            }
        }
        return len;
    }
    // int BinarySearch(vector<int>&dp,int start,int end,nums[i])
};