class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        vector<int> freq(26, 0);

        for(char x : word) {
            freq[x - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0){
                break;
            }

            int push = (i / 8) + 1;
            ans += freq[i] * push;
        }
        // for(int i = 0; i < n; i++) {
        //     ans += (i / 8) + 1;
        // }

        return ans;
    }
};