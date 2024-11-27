class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0,p=1,i=0,j=0;

        while(j<nums.size()){
            //grow
            p*=nums[j];
            //shrink
            while(p>=k && i<=j){
                p=p/nums[i];
                i++;
            }
            //ans update
            ans=ans+(j-i+1);

            j++;
        }
        return ans;
    }
};