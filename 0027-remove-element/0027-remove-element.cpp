class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int newPos = 0; 
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != val) {
                arr[newPos] = arr[i]; 
                newPos++; 
            }
        }
        
        return newPos; 
    }
};
