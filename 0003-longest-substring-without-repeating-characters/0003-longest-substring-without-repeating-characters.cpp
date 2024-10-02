class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;
        int count=0;
        int last=0;
        for(int i=0;i<s.size();i++){
        if (map.find(s[i]) != map.end() && map[s[i]] >= last){
           last = map[s[i]] + 1;
         }
             map[s[i]] = i;
            count= max(count, i - last + 1);
        }
        return count;
    }
};