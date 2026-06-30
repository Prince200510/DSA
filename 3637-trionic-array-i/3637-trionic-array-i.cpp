class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;

        if(n < 4) {
            return false;
        }

        while(i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        if(i == 1 || i == n) {
            return false;
        }

        int dec = i;
        while(i < n && nums[i] < nums[i - 1]) {
            i++;
        }

        if(i == dec || i == n) {
            return false;
        }

        int inc = i;
        while(i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        // if(i == inc || i == n) {
        //     return false;
        // }

        return true;
    }
};