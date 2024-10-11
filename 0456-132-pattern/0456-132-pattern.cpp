class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        if(nums.size()<3){
            return false;
        }
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.top()>nums[i]){
                if(st.size()>1 && nums[i]>=0){
                    return true;
                }
                else{
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};