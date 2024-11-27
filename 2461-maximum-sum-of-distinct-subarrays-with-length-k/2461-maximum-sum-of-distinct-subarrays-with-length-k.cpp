class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long i =0,j=0,sum=0,ans=0;
        map<long long,long long>mpp;
        while(j<nums.size()){
          sum+=nums[j];
          mpp[nums[j]]++;

          if(j-i+1==k){
            if(mpp.size()==k) ans=max(ans,sum);
            sum-=nums[i];
            mpp[nums[i]]--;
            if(mpp[nums[i]]==0) mpp.erase(nums[i]);
            i++;
          }
          j++;
        }
        return ans;
    }
};