class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        vector<int> arr;

        for(char x : s) {
            arr.push_back(x - '0');
        }

        // int prod = 1;
        // for(int i = 0; i < arr.size(); i++) {
        //     prod *= arr[i] ;
        // }
        sort(arr.begin(), arr.end());
        int k = arr.size();
        return arr[k - 1] * arr[k - 2];
    }
};