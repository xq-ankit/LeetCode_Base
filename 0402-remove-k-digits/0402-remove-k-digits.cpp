class Solution {
public:
    string removeKdigits(string s, int k) {
        string ans;
        stack<char>st;
        int n=s.size();
        if(n==k){
            return "0";
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && s[i]-'0'<st.top()-'0' && k>0){
                st.pop();
                k--;
            }
            st.push(s[i]);
            }
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
           int idx = 0;
            while (idx < ans.size() && ans[idx] == '0') {
            idx++;
            }
            ans=ans.substr(idx);
        
            return ans.empty() ? "0" : ans;
    }
};