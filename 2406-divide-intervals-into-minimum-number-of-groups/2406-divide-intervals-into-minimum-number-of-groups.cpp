class Solution {
public:
map<int,int>mpp;

    int minGroups(vector<vector<int>>& intervals) {
         for (auto &it : intervals) {
            mpp[it[0]]++;
            mpp[it[1]+1]--;
        }
        
       int sum=0;
       int ans=1;
       for(auto &it : mpp){
        sum+=it.second;
        ans=max(ans,sum);
       }
    return ans;
       
    }

};