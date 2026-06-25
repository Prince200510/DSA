class Solution {
public:
    int maxFreqSum(string s) {
        // int maxs = INT_MIN;
        int vowel = 0;
        int consont = 0;
        unordered_map<char, int> mp;

        for(char x : s) {
            mp[x]++;
        }

        for(auto x : mp) {
            if(x.first == 'a' || x.first == 'e' || x.first == 'i' || x.first == 'o' || x.first == 'u') {
                vowel = max(vowel, x.second);
            } else {
                consont = max(consont, x.second);
            }
        }

        // for(char x : s) {
        //     if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        //         vowel++;
        //     } else {
        //         consont++;
        //     }
        // }
        return vowel + consont;
    }
};