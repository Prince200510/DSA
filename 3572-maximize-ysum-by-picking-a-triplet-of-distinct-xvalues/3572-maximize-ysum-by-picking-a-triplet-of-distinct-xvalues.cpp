class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> mp;

        for(int i = 0; i < x.size(); i++) {
            mp[x[i]] = max(mp[x[i]], y[i]);
        }

        if(mp.size() < 3) {
            return -1;
        }

        vector<int> p;
        for(auto &[a, b] : mp) {
            p.push_back(b);
        }

        sort(p.rbegin(), p.rend());

        return p[0] + p[1] + p[2];
        // sort(x.begin(), x.end());
        // sort(y.begin(), y.end());

        // int maxs = INT_MIN;

        // for(int i = 0; i < x.size(); i++) {
        //     for(int j = 0; j < x.size(); j++) {
        //         for(int k = 0; k < x.size(); k++) {
        //             if(x[i] != x[j] && x[j] != x[k] && x[k] != x[i]) {
        //                 int s = y[i] + y[j] + y[k];
        //                 maxs = max(maxs, s);
        //             }
        //         }
        //     }
        // }

        // return maxs == INT_MIN ? -1 : maxs;
    }
};