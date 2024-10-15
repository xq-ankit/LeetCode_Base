class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> map;  // To count occurrences of each character
        stack<char> st;  // Stack to store the result characters
        vector<bool> inStack(26, false);  // To track if a character is in the stack
        
        // Count the frequency of each character
        for (char c : s) {
            map[c]++;
        }

        for (char c : s) {
            map[c]--;  // Decrease the frequency of the current character

            if (inStack[c - 'a']) {
                continue;  // If the character is already in the stack, skip it
            }

            // Maintain lexicographical order, pop from the stack while the top of the stack
            // is greater than the current character and can still appear later
            while (!st.empty() && st.top() > c && map[st.top()] > 0) {
                inStack[st.top() - 'a'] = false;  // Mark the popped character as not in the stack
                st.pop();
            }

            st.push(c);  // Push the current character to the stack
            inStack[c - 'a'] = true;  // Mark it as added
        }

        // Collect the result from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());  // The stack produces reverse order, so reverse it
        return ans;
    }
};
