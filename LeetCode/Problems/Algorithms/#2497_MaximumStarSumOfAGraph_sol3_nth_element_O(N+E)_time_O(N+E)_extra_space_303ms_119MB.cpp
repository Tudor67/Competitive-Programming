class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        const int N = vals.size();
        
        vector<vector<int>> neighborValues(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            if(vals[b] > 0){
                neighborValues[a].push_back(vals[b]);
            }
            if(vals[a] > 0){
                neighborValues[b].push_back(vals[a]);
            }
        }
        
        int res = *max_element(vals.begin(), vals.end());
        for(int node = 0; node < N; ++node){
            vector<int>& v = neighborValues[node];
            if(0 < k && k < (int)v.size()){
                nth_element(v.begin(), v.end() - k, v.end());
            }

            int sum = vals[node];
            for(int i = 0; i < min(k, (int)v.size()); ++i){
                sum += v[(int)v.size() - 1 - i];
            }

            res = max(res, sum);
        }
        
        return res;
    }
};