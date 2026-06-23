class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char c : num){
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        string result;

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        int index =  0;

        while(index < result.size() && result[index] == '0') {
            index++;
        }

        result = result.substr(index);

        return result.empty() ? "0" : result;
    }
};