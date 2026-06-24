class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // int n = tokens.size();
        // string token = "";
        stack<int> st;

        // for(string x : tokens) {
        //    token += x;
        // }

        for(string x : tokens) {
            if(x == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            } else if(x == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            } else if(x == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            } else if(x == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            } else {
                int x1 = stoi(x);
                st.push(x1);
            }
        }
        return st.top();
    }
};