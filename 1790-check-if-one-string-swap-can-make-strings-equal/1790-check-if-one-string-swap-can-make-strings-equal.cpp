class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char,int>mpp;
        map<char,int>mpp2;
        for(char c:s1){
            mpp[c]++;
        }
        for(char c:s2){
            mpp2[c]++;
        }

        for(char c:s1){
            if(mpp[c]!=mpp2[c]){
                return false;
            }
        }
        int count=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
        return count==2 || count==0;

    }
};