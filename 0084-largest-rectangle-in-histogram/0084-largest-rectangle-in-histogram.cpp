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










// Approch 2 :
// in one iteration in pse the element we are pop for them the new element is the nse.
class Solution {
public:
    int largestRectangleArea(vector<int>& a ) {
        int n=a.size();
        stack<int>st;
        vector<int>pse;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                int element=st.top();st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int area=a[element]*(nse-pse-1);
                ans=max(ans,area); }
                st.push(i);
        }
        while(!st.empty()){
                int element=st.top();st.pop();
                int nse=n;
                int pse=st.empty()?-1:st.top();
                int area=a[element]*(nse-pse-1);
                ans=max(ans,area); 
        }
        return ans;
    }
};
