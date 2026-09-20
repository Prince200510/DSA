class Solution {
public:
    int reverseDegree(string s) {
        int i = 1;
        int sums = 0;

        for(char c : s) {
            int a = 26 - (c - 'a');
            int p = a * i;
            sums += p;
            i++;
        }
        return sums;
    }
};