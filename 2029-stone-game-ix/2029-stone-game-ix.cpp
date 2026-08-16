class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};

        for(int x : stones) {
            count[x % 3]++;
        }

        if(count[1] == 0 && count[2] == 0) {
            return false;
        }

        if(count[0] % 2 == 0) {
            return count[1] > 0 && count[2] > 0;
        }

        return abs(count[1] - count[2]) > 2;
        // int sums = 0;

        // for(int x : stones) {
        //     sums += x;
        // }
 
        // if(sums % 3 == 0) {
        //     return false;
        // } 

        // return true;
    }
};