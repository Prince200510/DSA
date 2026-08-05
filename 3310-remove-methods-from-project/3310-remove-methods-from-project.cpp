class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        
        for(auto &x : invocations) {
            adj[x[0]].push_back(x[1]);
        }

        vector<bool> sup(n, false);
        queue<int> q;
        q.push(k);
        sup[k] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nb : adj[node]) {
                if(!sup[nb]) {
                    sup[nb] = true;
                    q.push(nb);
                }
            }
        }

        bool possible = true;

        for(auto e : invocations) {
            if(!sup[e[0]] && sup[e[1]]) {
                possible = false;
                break;
            }
        }

        vector<int> ans;

        if(!possible) {
            for(int i = 0; i < n; i++) {
                ans.push_back(i);
            } 
        } else {
            for(int i = 0; i < n; i++) {
                if(!sup[i]) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};