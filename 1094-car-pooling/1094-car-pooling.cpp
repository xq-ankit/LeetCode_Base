class Solution {
public:
map<int,int>mpp;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(auto &it :trips){
            mpp[it[1]]=it[0];
            mpp[it[2]+1]=-it[0];
        }
        int sum=0;
        for(auto &it : mpp){
            // cout<<it.first<<" "<<it.second<<endl;
            sum+=it.second;
            if(sum>capacity){
                return false;
            }
        }
        return true;
    }
};