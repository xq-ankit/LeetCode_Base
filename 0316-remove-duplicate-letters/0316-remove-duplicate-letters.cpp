class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]=i;
        }
        stack<char>st;
        vector<bool>visted(26,false);
        for(int i=0;i<s.size();i++){
            if(visted[s[i]-'a']==true)continue;
            while(!st.empty() && st.top()>=s[i] && mpp[st.top()]>i){
                visted[st.top()-'a']=false;
                st.pop();
            }
            visted[s[i]-'a']=true;
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};