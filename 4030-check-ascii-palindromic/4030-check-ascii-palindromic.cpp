class Solution {
public:
    bool isPalindromic(string s) {
        // int n = s.length();
        string merges = "";

        for(char x : s) {
            int a = (int)x;
            string b = bitset<8>(a).to_string();
            merges += b;
        }

        int left = 0;
        int right = merges.size() - 1;

        bool pal = true;
        while(left < right) {
            if(merges[left] != merges[right]) {
                pal = false;
                break;
            }

            left++;
            right--;
        }

        if(pal) {
            return true;
        }

        return false;
    }
};