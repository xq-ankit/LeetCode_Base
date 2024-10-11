class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>pse(n,-1);
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }
while(!st.empty()){
    st.pop();
}

         for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
    for(int i=0;i<n;i++){
        int width=nse[i]-pse[i]-1;
        int temp=h[i]*width;
        ans=max(ans,temp);

    }
    return ans;
    



    }
};