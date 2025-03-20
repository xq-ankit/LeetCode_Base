class Solution {
    public static int maxSubArray(int[] nums) {
        int sum = Integer.MIN_VALUE;
        int n = nums.length;
        int temp = 0;
        for(int i = 0; i < n; i++){
        temp += nums[i];
        sum = Math.max(temp, sum);
        if(temp<0)
            temp=0;
            
        }

        return sum;
    }
}