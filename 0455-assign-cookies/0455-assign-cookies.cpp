class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
            int i=0,j=0;
            int count=0;
            while(i<g.size() && j<s.size()){
                if(s[j]>=g[i]){
                    count++;
                    // cout<<g[i]<<" "<<s[i]<<" "<<count;
                    j++;
                    i++;
                }
                else{
                    j++;
                }
            }

            return count;



    }
};