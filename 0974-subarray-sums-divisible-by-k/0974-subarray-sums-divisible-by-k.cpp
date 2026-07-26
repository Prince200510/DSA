class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix_sum = 0;

        for(int x : nums) {
            prefix_sum += x;

            int r = prefix_sum % k;

            if(r < 0) {
                r += k;
            }

            if(mp.count(r)) {
                count += mp[r];
            }

            mp[r]++;
        }
        // for(int i = 0; i < n; i++) {
        //     int sums = 0;
        //     for(int j = i; j < n; j++) {
        //         sums += nums[j];

        //         if(sums % k == 0) {
        //             count++;
        //         }
        //     }
        // }

        return count;
    }
};