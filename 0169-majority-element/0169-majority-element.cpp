class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto i:map){
            if(i.second>n/2){
                return i.first;
            }
        }
        return -1;
    }
};