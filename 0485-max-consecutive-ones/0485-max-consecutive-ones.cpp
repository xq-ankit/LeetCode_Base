class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int val=INT_MIN,temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                val=max(val,temp);
                temp=0;
            }
            else
                temp++;
        }
        return max(temp,val);

    }
};