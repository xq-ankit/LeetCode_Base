class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>map;
        stack<char>st;
        for(char c:s){
            map[c]++;
        }
        vector<bool>visited(26,false);
        for(char c:s){
             map[c]--;
            if( visited[c-'a']==true) continue;
            while(!st.empty() && st.top()>=c && map[st.top()]>=1){
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
             visited[c-'a']=true;
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