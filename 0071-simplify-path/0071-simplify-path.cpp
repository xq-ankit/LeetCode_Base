class Solution {
public:
    string simplifyPath(string path) {
        stringstream s(path);
        string token;
        stack<string> st;
        string ans = "";
        while (getline(s, token, '/')) {
            if (token == "" || token == ".") continue; 
            else if (token == "..") {
                if (!st.empty()) st.pop();  
            } else {
                st.push(token);  }
        }

       
        while (!st.empty()) {
            ans = "/" + st.top() + ans; 
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};
