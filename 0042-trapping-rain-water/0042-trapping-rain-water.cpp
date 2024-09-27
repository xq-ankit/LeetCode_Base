class Solution {
public:
    int trap(vector<int>& arr) {
       int i=0,leftmax=arr[i],j=arr.size()-1,rightmax=arr[j];
       int sum=0;
       while(i<=j){
        if(arr[i]<=arr[j]){
            if(leftmax<=arr[i]){
                leftmax=arr[i];
            }
            else{
                sum+=leftmax-arr[i];
            }
            i++;
        }
        else{
             if(rightmax<=arr[j]){
                rightmax=arr[j];
            }
            else{
                sum+=rightmax-arr[j];
            }
            j--;
        }
       }
       return sum;
    }
};