class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> pro(n, 0.0);
        pro[start_node] = 1.0;

        for(int i = 0; i < n - 1; i++) {
            bool update = false;

            // for(auto& e : edges) {
            //     int u = e[0];
            //     int v = e[1];
            //     int wt = 0;

            //     for(int i = 0; i < succProb.size(); i++) {

            //     }
            // }
            for(int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double wt = succProb[j];

                if(pro[u] * wt > pro[v]) {
                    pro[v] = pro[u] * wt;
                    update = true;
                }

                if(pro[v] * wt > pro[u]) {
                    pro[u] = pro[v] * wt;
                    update = true;
                }
            }

            if(!update) {
                break;
            }
        }
        return pro[end_node];
    }
};