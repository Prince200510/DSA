class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> p;

        for(int a : arr) {
            p.push_back({abs(a - x), a});
        }

        sort(p.begin(), p.end());
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(p[i].second);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};