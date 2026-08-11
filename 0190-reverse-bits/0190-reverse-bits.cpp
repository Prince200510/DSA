class Solution {
public:
    string binarys(int n) {
        string result = "";

        while(n != 0) {
            int r = n % 2;
            result += char('0' + r);
            n /= 2;
        }

        while(result.length() < 32) {
            result += '0';
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

    int reverseBits(int n) {
        string s = binarys(n);
        reverse(s.begin(), s.end());
        int decimal = stoi(s, nullptr, 2);
        return decimal;    
    }
};