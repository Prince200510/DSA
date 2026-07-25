class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            int sums = 0;
            for(int j = i; j < n; j++) {
                sums += nums[j];
                if(sums == k) {
                    count++;
                }
            }
        }
        return count;
    }
};