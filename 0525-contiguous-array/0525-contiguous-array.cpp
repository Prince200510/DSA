class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sums = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                sums += 1;
            } else {
                sums -= 1;
            }

            if(mp.count(sums)) {
                ans = max(ans, i - mp[sums]);
            } else {
                mp[sums] = i;
            }
        }

        // for(int i = 0; i < n; i++) {
        //     int count_z = 0;
        //     int count_1 = 0;

        //     for(int j = i; j < n; j++) {
        //         if(nums[j] == 0) {
        //             count_z++;
        //         } else {
        //             count_1++;
        //         }

        //         if(count_z == count_1) {
        //             ans = max(ans, j - i + 1);
        //         }
        //     }
        // }
        return ans;
    }
};