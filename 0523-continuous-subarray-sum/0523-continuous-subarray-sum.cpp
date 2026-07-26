class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int prefix_sum = 0;
        
        for(int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            int r = prefix_sum % k;

            if(r < 0) {
                r += k;
            }

            if(mp.count(r)) {
                if(i - mp[r] >= 2) {
                    return true;
                }
            } else {
                mp[r] = i;
            }

           // mp[r]++;
        }
        // for(int i = 0; i < n; i++) {
        //     int sums = 0;
        //     for(int j = i ; j < n; j++) {
        //         sums += nums[j];

        //         if(j - i + 1 >= 2 && sums % k == 0) {
        //             return true;
        //         }
        //     }
        // }

        return false;
    }
};