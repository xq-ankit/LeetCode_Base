class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n=nums.length;
        int[]left=new int[n];
        int[]right=new int[n];
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=nums[i]*left[i-1];
            }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i];

        }
        int[]sol=new int[n];
        for(int i=0;i<n;i++){
            if(i==0){
                sol[i]=right[1]*1;
            }
            else if(i==n-1){
                sol[i]=left[n-2]*1;
            }
            else{
                sol[i]=left[i-1]*right[i+1];
            }
        }
        return sol;



        
    }
}