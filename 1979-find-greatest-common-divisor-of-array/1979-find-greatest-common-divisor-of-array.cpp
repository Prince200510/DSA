class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++) {
        //     mn = min(mn, nums[i]);
        //     mx = max(mx, nums[i]);
        // }

        int g = gcd(mn, mx);

        return g;
    }
};