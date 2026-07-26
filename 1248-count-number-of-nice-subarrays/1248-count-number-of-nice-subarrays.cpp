class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix = 0;

        for(int x : nums) {
            if(x % 2) {
                prefix++;
            }

            if(mp.count(prefix - k)) {
                ans += mp[prefix - k];
            }

            mp[prefix]++;
        }
        // for(int i = 0; i < n; i++) {
        //     int odd = 0;
        //     for(int j = i; j < n; j++) {
        //         if(nums[j] % 2 == 1) {
        //             odd++;
        //         }

        //         if(odd == k) {
        //             ans++;
        //         } else if(odd > k) {
        //             break;
        //         }
        //     }
        // }
        return ans;
    }
};