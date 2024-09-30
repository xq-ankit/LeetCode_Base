class Solution {
    public static int singleNumber(int[] nums) {
        int Elexor=0;
        for(int i=0;i<nums.length;i++){
            Elexor=Elexor^nums[i];
        }
        return Elexor;
    }
    }
