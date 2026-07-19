class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<int> in_stack(26, 0);
        stack<char> st;

        for(char c : s) {
            freq[c - 'a']++;
        }

        for(char c : s) {
            freq[c - 'a']--;

            if(in_stack[c - 'a']) {
                continue;
            }

            while(!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                in_stack[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(c);
            in_stack[c - 'a'] = 1;
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