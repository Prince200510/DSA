class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(char x : s) {
            if(x != ')') {
                st.push(x);
            } else {
                string temp = "";

                while(!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                st.pop();

                for(char x : temp) {
                    st.push(x);
                }
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};