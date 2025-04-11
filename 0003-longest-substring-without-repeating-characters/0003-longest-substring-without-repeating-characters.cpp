class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mpp;
        int len=0;
        int last=0;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end() && mpp[s[i]]>=last){
                last=mpp[s[i]]+1;
            }
            mpp[s[i]]=i;
            len=max(len,i-last+1);
        }
        return len;
    }
};