class Solution {
public:
    bool hasAlternatingBits(int n) {
        string b = bitset<32>(n).to_string();
        b.erase(0, b.find_first_not_of('0'));

        for(int i = 1; i < b.size(); i++) {
            if(b[i] == b[i - 1]) {
                return false;
            }
        }

        return true;
    }
};