class Solution {
public:
void permutation(vector<vector<int>>&ans,vector<int>& nums,vector<bool>&freq,vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }

    for(int i=0;i<nums.size();i++){
        if(freq[i])continue;
        freq[i]=true;
        temp.push_back(nums[i]);
        permutation(ans,nums,freq,temp);
        temp.pop_back();
        freq[i]=false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<bool>freq(nums.size(),false);
        vector<int> temp;
        permutation(ans,nums,freq,temp);
        return ans;

    }
};