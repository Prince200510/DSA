class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int f_mx = nums[n - 1];
        int s_mx = nums[n - 2];
        int t_mx = nums[n - 3];
        int f_mn = nums[0];
        int s_mn = nums[1];
        int t_mn = nums[n - 1];

        int mx = INT_MIN;
        int mx1 = (f_mx * s_mx * t_mx);
        int mn1 = (f_mn * s_mn * t_mn);

        mx = max(mx1, mn1);

        return mx;
    }
};