class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int>a(nums.size()+2);
        a[0]=1;
        a[a.size()-1]=1;
        for(int i=1;i<a.size()-1;i++){
            a[i]=nums[i-1];
        }
        return max_coin(a,0,a.size()-1);
    }
    int max_coin(vector<int>a,int i,int j){
        if(i+1==j){
            return 0;
        }
        int ans=INT_MIN;
        for(int k=i+1;k<j;k++){
            int left=max_coin(a,i,k);
            int right=max_coin(a,k,j);
            int self=a[i]*a[k]*a[j];
            ans=max(ans,left+self+right);
        }
        return ans;
    }
};