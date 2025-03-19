class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        stack<int>st;
        vector<int>v(num2.size());
        for(int i=num2.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=num2[i]){
                st.pop();
            }
            if(st.empty()){
                v[i]=-1;
                }
            else{
                v[i]=st.top();
            }
            st.push(num2[i]);
        }
        vector<int>ans(num1.size());
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<=num2.size();j++){
                if(num1[i]==num2[j]){
                    ans[i]=v[j];
                    break;
                }
            }
        }
        return ans;
    }
};