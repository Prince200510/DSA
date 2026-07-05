class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string number = "";

        for(int i = 0; i < nums.size(); i++) {
            number += to_string(nums[i]);
        }

        vector<int> ans;
        for(char x : number) {
            ans.push_back(x - '0');
        }

        return ans;
    }
};