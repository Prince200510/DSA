class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        
        while(left <= right) {
            long long sums = (left * left) + (right * right);

            if(sums == c) {
                return true;
            } else if(sums < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};