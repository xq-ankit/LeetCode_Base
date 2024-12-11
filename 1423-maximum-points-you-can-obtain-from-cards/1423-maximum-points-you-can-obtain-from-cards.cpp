class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left_Sum=0;
        int right_Sum=0;
        int sum=0;
       for(int i=0;i<k;i++){
        left_Sum+=cardPoints[i];
        }
        sum=left_Sum;

        int rightlen=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            left_Sum-=cardPoints[i];
            right_Sum+=cardPoints[rightlen--];
            sum=max(sum,left_Sum+right_Sum);
        }
        return sum;
    }
};
