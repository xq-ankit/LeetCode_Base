class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMaxs(nums);
        long long minSum = sumSubarrayMins(nums); 
        return maxSum - minSum; 
    }

    // Function to find the Next Greater Element (NGE) for each index
    vector<int> findNGE(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to find the Previous Greater or Equal Element (PGE or Equal) for each index
    vector<int> findPGEorEqual(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to calculate the sum of maximums of all subarrays
    long long sumSubarrayMaxs(vector<int>& arr) {
        long long total = 0;

        // Find NGE and PGE arrays
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGEorEqual(arr);

        for (int i = 0; i < arr.size(); i++) {
            int noOfElementsOnLeftForI = i - pge[i];
            int noOfElementsOnRightForI = nge[i] - i;

            // Total contribution of arr[i] to all subarray maximums
            long long subarrayCount = (long long) noOfElementsOnLeftForI * noOfElementsOnRightForI;
            long long contribution = (subarrayCount * arr[i]);
            total += contribution;
        }

        return total;
    }

    // Function to find the Next Smaller Element (NSE) for each index
    vector<int> findNSE(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to find the Previous Smaller or Equal Element (PSE or Equal) for each index
    vector<int> findPSEorEqual(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to calculate the sum of minimums of all subarrays
    long long sumSubarrayMins(vector<int>& arr) {
        long long total = 0;

        // Find NSE and PSE arrays
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEorEqual(arr);

        for (int i = 0; i < arr.size(); i++) {
            int noOfElementsOnLeftForI = i - pse[i];
            int noOfElementsOnRightForI = nse[i] - i;

            // Total contribution of arr[i] to all subarray minimums
            long long subarrayCount = (long long) noOfElementsOnLeftForI * noOfElementsOnRightForI;
            long long contribution = (subarrayCount * arr[i]);
            total += contribution;
        }

        return total;
    }
};
