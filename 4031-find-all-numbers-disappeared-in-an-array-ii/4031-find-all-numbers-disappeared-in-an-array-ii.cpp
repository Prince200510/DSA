class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        long long p = (long long)lower - 1;

        for(int x : nums) {
            if(x < lower || x > upper) {
                continue;
            }

            if((long long)x > p + 1) {
                ans.push_back({(int)(p + 1), x - 1});
            }

            p = x;
        }

        if(p < upper) {
            ans.push_back({(int)(p + 1), upper});
        }

        return ans;
    }
};