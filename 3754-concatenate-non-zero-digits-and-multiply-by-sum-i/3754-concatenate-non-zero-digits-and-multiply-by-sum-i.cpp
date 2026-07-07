class Solution {
public:
    long long sumAndMultiply(int n) {
        string number = to_string(n);
        // int length = to_string(n);
        long long sums = 0;
        string non_zero = "";

        for(char x : number) {
            if(x != '0') {
                non_zero += x;
                sums += x - '0';
            }
        }

        if(non_zero.empty()) {
            return 0;
        }
        
        return sums * stoi(non_zero);
    }
};