class Solution {
     public int[] searchRange(int[] nums, int target) {
        int[] sol={-1,-1};
        int start=binarySearch(nums, target, true);
        int end=binarySearch(nums, target, false);
        sol[0]=start;
        sol[1]=end;
        return sol;

    }

    public static int binarySearch(int[] nums, int target, boolean findStart) {
    int start = 0, end = nums.length - 1, ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] > target) {
            end = mid - 1;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            ans = mid;
            if (findStart) {
                end = mid - 1; 
            } else {
                start = mid + 1; 
            }
        }
    }

    return ans;
}

}
