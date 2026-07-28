class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(char x : s) {
            mp[x]++;
        }

        string left = "";
        string right = "";
        string mid = "";

        for(char c = 'a'; c <= 'z'; c++) {
            left.append(mp[c] / 2, c);

            if(mp[c] % 2) {
                mid += c;
            }
            // if(p.second % 2 == 0) {
            //     left.append(p.second / 2, p.first);
            //     // right.append(p.second / 2, p.first);
            // } else {
            //     mid += (p.first);
            // }
        }

        right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};