class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        /*
        if orginal arr is [a,b,c,d]
        derived arr is [a^b,b^c,c^d,d^a];
        to check id a orginal array exist the xor of the derived array should be 0;
        */
        int xor_val=0;
        for(int i=0;i<derived.size();i++){
            xor_val^=derived[i];
        }
        return xor_val==0;
    }
};