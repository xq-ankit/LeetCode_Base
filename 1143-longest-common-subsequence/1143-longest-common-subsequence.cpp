class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return LCS(text1,text2,0,0,dp);
    }
    int LCS(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.size() || j==s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+LCS(s1,s2,i+1,j+1,dp);
        }else{
            int f=LCS(s1,s2,i+1,j,dp);
            int s=LCS(s1,s2,i,j+1,dp);
            ans=max(f,s);

        }
        return dp[i][j]=ans;


    }


// int LCSTab(string s1,string s2,vector<vector<int>>&dp){
   
// }



























};