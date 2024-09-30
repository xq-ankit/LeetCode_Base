class Solution {
    public void rotate(int[] nums, int k) {
      rotate_array(nums,k);
  }
   public static void rotate_array(int[] arr,int k){
        int n=arr.length;
        k=k%n;
        reverse(arr,0,n-k-1);//first k element
        reverse(arr,n-k,n-1);//last k element;
        reverse(arr,0,n-1);//reverse entire element
    }
    public static int[] reverse(int[] arr,int start,int end){
        int i=start;
        int j=end;
        while(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        return arr;

        
    }
}