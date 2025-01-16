class Solution {
    public static int findMaxConsecutiveOnes(int[] nums) {
        int count=0 ,temp=-1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=1){
                if(temp<count) {temp=count;}
                count=0;
                continue;
            }
            count++;
            }
        return Math.max(count,temp);
    }
}