class Solution {
    //Dutch National Flag Approach
    public void sortColors(int[] nums) {
        Sort2(nums);
        }
     public static void Sort2(int[] nums){
        int low=0,mid=0,high=nums.length-1;
        while(mid<=high){
            if(nums[mid]==0) {Swap(nums,mid,low); low++;mid++;}
            else if((nums[mid]==2)){Swap(nums, mid, high);high--;}
            else {mid++;}
        }
    }
    public static void Swap(int [] nums,int a, int b){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
}