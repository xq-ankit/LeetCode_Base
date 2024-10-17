class Solution {
    public int searchInsert(int[] nums, int target) {
        return lowerBound(nums,nums.length,target);
    }
    public static int lowerBound(int []arr, int n, int x) {
        int start=0,end=n-1,result=-10;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==x){
                return mid;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else {
                start=mid+1;
            }
            
           }
           return start;
          
    }
} 
   