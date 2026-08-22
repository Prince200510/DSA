class Solution {
public:
    bool checkDivisibility(int n) {
        int sums = 0, product = 1, original = n;

        while(n != 0) {
            int digit = n % 10;
            sums += digit;
            product *= digit;
            n /= 10;
        }

        return original % (sums + product) == 0;
    }
};