class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int m = *min_element(nums.begin(), nums.end());
        int a = 0;

        for(int x : nums) {
            a += x - m;
        }

        return a;
    }
};