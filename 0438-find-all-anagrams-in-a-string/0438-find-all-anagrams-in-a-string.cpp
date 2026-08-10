class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(p.size() > s.size()) {
            return ans;
        }

        vector<int> freq(26, 0);
        vector<int> freq_window(26, 0);
        int m = p.size();

        for(char c : p) {
            freq[c - 'a']++;
        }

        for(int i = 0; i < m; i++) {
            freq_window[s[i] - 'a']++;
        }

        if(freq_window == freq) {
            ans.push_back(0);
        }

        for(int i = m ; i < s.size(); i++) {
            freq_window[s[i] - 'a']++;
            freq_window[s[i - m] - 'a']--;

            if(freq_window == freq) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};