class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;

        for(int x : arr) {
            mp[x]++;
        }

        int ans = -1;
        for(auto &x : mp) {
            if(x.first == x.second) {
                ans = max(ans, x.first);
                //int b = x.second;
                //if(x.second % x.first == 0) {
                //    return x.first;
                //}
            }
        }
        return ans;
    }
};