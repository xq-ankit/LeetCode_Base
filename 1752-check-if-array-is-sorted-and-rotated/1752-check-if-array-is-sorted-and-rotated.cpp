class Solution {
public:
    bool check(vector<int>& num) {
        int count=0;
        int n=num.size();
        for(int i=1;i<=n;i++){
            if(num[(i-1)%n]>num[(i)%n]){
                count++;
            }
        }
        return count<=1;
    }
};