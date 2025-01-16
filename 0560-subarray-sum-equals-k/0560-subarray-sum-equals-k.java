class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> list=new HashMap<>();
        int sum=0,count=0;
        list.put(0,1);
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            int rem=sum-k;
            count+=list.getOrDefault(rem,0);
            list.put(sum,(list.getOrDefault(sum,0)+1));
        }
        return count;
    }
}