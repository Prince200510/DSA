class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s : strs) {
            string sort_s = s;
            sort(sort_s.begin(), sort_s.end());
            mp[sort_s].push_back(s);
        }

        vector<vector<string>> result;
        for(auto pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};