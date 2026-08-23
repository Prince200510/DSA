class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int h = n / 2;

        int left = 0, right = 0;
        int diff = 0;

        for(int i = 0; i < h; i++) {
            if(num[i] == '?') {
                left++;
            } else {
                diff += num[i] - '0';
            }
        }

        for(int i = h; i < n; i++) {
            if(num[i] == '?') {
                right++;
            } else {
                diff -= num[i] - '0';
            }
        }

        // if(left != right) {
        //     int dif = left - right;
        //     return true;
        // }

        int r = 9 * (right - left);
        return 2 * diff != r;
    }
};