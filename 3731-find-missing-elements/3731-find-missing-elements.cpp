class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        // nums.erase(find(nums.begin(), nums.end(), mx));
        // nums.erase(find(nums.begin(), nums.end(), mn));
        vector<int> ans;
        int j = 0;
        int n = nums.size();

        for(int i = mn; i <= mx; i++) {
            if(j < n && nums[j] == i) {
               // ans.push_back(i);
               // break;
               j++;
            } else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};