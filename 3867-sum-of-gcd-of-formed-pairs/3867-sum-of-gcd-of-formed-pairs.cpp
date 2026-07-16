class Solution {
public:
    int gcds(int a, int b) {
        if(b == 0) {
            return a;
        }

        return gcds(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> prefix;
        int mx = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            prefix.push_back(gcds(nums[i], mx));
        }

        sort(prefix.begin(), prefix.end());
        long long ans = 0;
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            ans += gcds(prefix[left], prefix[right]);
            left++;
            right--;
        }

        return ans;
    }
};