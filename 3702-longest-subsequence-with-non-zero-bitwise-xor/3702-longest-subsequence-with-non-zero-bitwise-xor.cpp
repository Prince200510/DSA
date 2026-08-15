class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool no_zero = false;

        for(int num : nums) {
            x ^= num;

            if(num != 0) {
                no_zero = true;
            }
        }

        if(x != 0) {
            return nums.size();
        }

        if(no_zero) {
            return nums.size() - 1;
        }

        return 0;
    }
};