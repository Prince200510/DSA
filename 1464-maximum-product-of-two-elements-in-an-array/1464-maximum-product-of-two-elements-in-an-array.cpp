class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        priority_queue<int> pq;

        for(int x : nums) {
            pq.push(x);
        }

        while(pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            int mul = (a - 1) * (b - 1);
            mx = max(mx, mul);
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         mx = max(mx, ((nums[i] - 1) * (nums[j] - 1)));
        //     }
        // }

        return mx;
    }
};