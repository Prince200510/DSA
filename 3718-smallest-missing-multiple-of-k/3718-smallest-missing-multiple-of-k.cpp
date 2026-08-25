class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp;

        for(int x : nums) {
            mp.insert(x);
        }

        for(int i = 1; ; i++) {
            int m = k * i;

            if(mp.find(m) == mp.end()) {
                return m;
            }
        }
    }
};