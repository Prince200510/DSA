class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0;
        int p = 0;

        for(char c : moves) {
            if(c == 'L') {
                p--;
            } else if(c == 'R') {
                p++;
            } else {
                count++;
            }
        }

        return abs(p) + count;
    }
};