class Solution {
public:
    string binarys(int n) {
        string result = "";

        while(n != 0) {
            int r = n % 2;
            result += char('0' + r);
            n /= 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    int hammingWeight(int n) {
        string a = binarys(n);
        int count = 0;

        for(char x : a) {
            if(x == '1') {
                count++;
            }
        }    
        return count;
    }
};