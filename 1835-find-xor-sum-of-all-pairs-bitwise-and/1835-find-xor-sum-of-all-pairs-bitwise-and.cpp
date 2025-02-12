class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        //Distributivee property
        // (a&b)^(a&c)=a&(b^c);
        int xor_1=0,xor_2=0;

        for(int i=0;i<arr1.size();i++){
            xor_1^=arr1[i];
        }

        for(int i=0;i<arr2.size();i++){
            xor_2^=arr2[i];
        }

        return xor_1 & xor_2;
    }
};