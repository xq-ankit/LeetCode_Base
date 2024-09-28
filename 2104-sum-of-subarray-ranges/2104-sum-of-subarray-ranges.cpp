class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long minSum=sumSubarrayMaxs(nums);
        long long maxSum=sumSubarrayMins(nums);
        return minSum-maxSum;
    }


vector<int> findNGE(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            // If no smaller element is found, treat the boundary as arr.size()
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to find the Previous Smaller or Equal Element (PSE) for each index
    vector<int> findPGEorEqual(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            // If no previous smaller or equal element is found, treat the boundary as -1
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to calculate the sum of minimums of all subarrays
    long long sumSubarrayMaxs(vector<int>& arr) {
        long long total = 0; // Use long to prevent overflow

        // Find NSE and PSE arrays
        vector<int> nse = findNGE(arr);
        vector<int> pse = findPGEorEqual(arr);

        for (int i = 0; i < arr.size(); i++) {
            // Calculate the number of subarrays where arr[i] is the minimum element
            int noOfElementsOnLeftForI = i - pse[i];
            int noOfElementsOnRightForI = nse[i] - i;

            // Total contribution of arr[i] to all subarray minimums
            long long subarrayCount = (long) noOfElementsOnLeftForI * noOfElementsOnRightForI;
            long long contribution = (subarrayCount * arr[i]);
            total += contribution;
        }

        return total;
    }
































    vector<int> findNSE(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // If no smaller element is found, treat the boundary as arr.size()
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to find the Previous Smaller or Equal Element (PSE) for each index
    vector<int> findPSEorEqual(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // If no previous smaller or equal element is found, treat the boundary as -1
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    // Function to calculate the sum of minimums of all subarrays
    long long  sumSubarrayMins(vector<int>& arr) {
        long long total = 0; // Use long to prevent overflow

        // Find NSE and PSE arrays
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEorEqual(arr);

        for (int i = 0; i < arr.size(); i++) {
            // Calculate the number of subarrays where arr[i] is the minimum element
            int noOfElementsOnLeftForI = i - pse[i];
            int noOfElementsOnRightForI = nse[i] - i;

            // Total contribution of arr[i] to all subarray minimums
            long long subarrayCount = (long) noOfElementsOnLeftForI * noOfElementsOnRightForI;
            long long contribution = (subarrayCount * arr[i]);
            total+=contribution;
        }

        return total;
    }
};