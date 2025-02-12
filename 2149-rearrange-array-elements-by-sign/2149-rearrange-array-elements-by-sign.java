class Solution {
    public static int[] rearrangeArray(int[] arr) {
        int n=arr.length,k=0,j=0;
        int neg[]=new int[n/2];
        int pos[]=new int[n/2];
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                neg[k++]=arr[i];
            }
            else pos[j++]=arr[i];

        }
        k=0;j=0;
        for(int i=0;i<n;i++){
            if(i%2!=0) arr[i]=neg[k++];
            else arr[i]=pos[j++];

        }
        return arr;
    }
}