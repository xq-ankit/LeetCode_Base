class Solution {
public:

int cal(char ch, int t1, int t2) {
    switch(ch) {
        case '+':
            return t2 + t1;
        case '-':
            return t2 - t1;
        case '*':
            return t2 * t1;
        case '/':
            return t2 / t1;
    }
    return 0; 
}

int evalRPN(vector<string>& s) {
    stack<int> st;  
    for(int i = 0; i < s.size(); i++) {
        if (isdigit(s[i][0]) || (s[i].size() > 1 && s[i][0] == '-')) {  
            st.push(stoi(s[i]));
        } else {
            int t1 = st.top(); st.pop();  
            int t2 = st.top(); st.pop();  
            int ans = cal(s[i][0], t1, t2);  
            st.push(ans); 
        }
    }
    return st.top(); 
}
};
