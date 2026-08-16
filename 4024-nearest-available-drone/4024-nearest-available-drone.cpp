class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int ans_min = INT_MAX;
        int ans = -1;

        for(int i = 0; i < n; i++) {
            int x = drones[i][0];
            int y = drones[i][1];
            int r = drones[i][2];

            int m = abs(x - target[0]) + abs(y - target[1]);
            // int k1 = r - m; 
            // ans_min = min(ans_min, k1);

            if(m <= r) {
                if(m < ans_min) {
                    ans_min = m;
                    ans = i;
                }
            }
        }

        return ans;
    }
};