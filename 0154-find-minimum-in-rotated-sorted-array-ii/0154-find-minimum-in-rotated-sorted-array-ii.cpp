class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        int ans=INT_MAX;
        while(start<=end){
            int mid=start+(end-start)/2;

                if(nums[start]<nums[end]){
                    ans=min(ans,nums[start]);
                    break;
                }


                 if (nums[start] == nums[mid]) {
                ans = min(ans, nums[start]);
                start++;
                continue;
            }
            if(nums[start]<=nums[mid]){
                ans=min(nums[start],ans);
                start=mid+1;
            }
            else{
                ans=min(nums[mid],ans);
                end=mid-1;
            }
        


        }
        return ans;



            }
};