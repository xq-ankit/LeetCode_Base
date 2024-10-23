class Solution {
public:
 vector<vector<int>>dp;
    int minDistance(string word1, string word2) {
        dp.resize(word1.size()+1,vector<int>(word2.size()+1,-1));
    return min_orp(word1,word2,0,0);


    }
    int min_orp(string s,string t,int i,int j){
        if(s.size()==i){
            return t.size()-j;
        }
       if(t.size()==j){
            return s.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            ans=min_orp(s,t,i+1,j+1);
        }
        else{
            int D=min_orp(s,t,i+1,j);
            int R=min_orp(s,t,i+1,j+1);
            int I=min_orp(s,t,i,j+1);
            ans=min({D,R,I})+1;
        }
        return dp[i][j]=ans;
    }
};