class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count=INT_MAX;
        int left=0;
        int right=0;
        int windowsum=0;
        while(right<nums.size()){
          windowsum+=nums[right++];

          while(windowsum>=target){
            count=min(count,right-left);
            windowsum-=nums[left++];
          }

        }
        return count!=INT_MAX?count:0;
    }
};