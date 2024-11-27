class Solution {
    public String reverseWords(String s) {
        return reveString(s);
    }
        public static String reveString(String s){
        s=s.trim(); 
        String[] arr=s.split("\s+"); 
        String ans="";
        for(int i=arr.length-1;i>=0;i--){
            ans+=arr[i]+" ";

        }
        return ans.trim();
    }
}