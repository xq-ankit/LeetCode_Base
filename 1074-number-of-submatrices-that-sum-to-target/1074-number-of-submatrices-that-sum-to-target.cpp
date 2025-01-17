class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // Precomputed the cummulative sum row-wise
        for(int r=0;r<matrix.size();r++){
            int cumSum=0;
            for(int c=0;c<matrix[0].size();c++){
                cumSum+=matrix[r][c];
                matrix[r][c]=cumSum;
            }
        }

        // now applaying LC:560 logic downward-direction
        int result=0;
        for(int startcol=0;startcol<matrix[0].size();startcol++){

            for(int j=startcol;j<matrix[0].size();j++){
                    unordered_map<int,int>mpp;
                    mpp.insert({0,1});
                    int sum=0;

                for(int row=0;row<matrix.size();row++){
                    sum+=matrix[row][j];
                    if(startcol>0){
                        sum-=matrix[row][startcol-1];
                    }

                    int req=sum-target;
                    if(mpp.find(req)!=mpp.end()){
                        result+=mpp[req];
                    }

                    mpp[sum]++;
                }
            }
        }
         
        return result;
    }
};