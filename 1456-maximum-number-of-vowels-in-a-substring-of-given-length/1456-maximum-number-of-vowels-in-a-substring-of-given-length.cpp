class Solution {
public:
    bool vowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    } 

    int maxVowels(string s, int k) {
        // int window = 0;
        int count = 0;
        int n = s.length();

        for(int i = 0; i < k; i++) {
            if(vowel(s[i])) {
                count++;
            }
        }

        int max_count = count;

        for(int i = k; i < n; i++) {
            if(vowel(s[i])) {
                count++;
            }

            if(vowel(s[i - k])) {
                count--;
            }
            max_count = max(max_count, count);
        }

        return max_count;
    }
};