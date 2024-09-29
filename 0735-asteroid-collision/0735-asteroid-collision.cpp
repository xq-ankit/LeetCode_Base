class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;
        stack<int>st;
        int n=ast.size();
        for(int i=0;i<n;i++){
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && ast[i]<0){
                int sum=st.top()+ast[i];
                if(sum<0){
                    st.pop();
                }
                else if(sum==0){
                    st.pop();
                    destroyed=true;
                    break;
                }
                else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed)
                st.push(ast[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};