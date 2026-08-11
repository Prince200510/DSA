class Solution {
public:
    string binary(int n) {
        string result = "";

        while (n != 0) {
            int r = n % 2;
            result += char('0' + r);
            n /= 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string convertDateToBinary(string date) {
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string dates = date.substr(8, 2);

        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(dates);

        string ans = binary(y) + "-" + binary(m) + "-" + binary(d);

        return ans;
    }
};