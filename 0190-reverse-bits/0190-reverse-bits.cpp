class Solution {
public:
    string reversess(string &s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }

    int reverseBits(int n) {
        bitset<32> b(n);
        string s = b.to_string();

        reversess(s);

        return stoi(s, nullptr, 2);
    }
};