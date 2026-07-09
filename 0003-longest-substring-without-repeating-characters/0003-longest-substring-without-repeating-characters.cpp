class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int max_length = 0;
        int left = 0;

        for(int right = 0; right < s.length(); right++) {
            char current = s[right];

            if(freq.count(current) && freq[current] >= left) {
                left = freq[current] + 1;
            }

            freq[current] = right;
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};