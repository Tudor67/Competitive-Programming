class Solution {
public:
    long long maximumImportance(int N, vector<vector<int>>& roads) {
        vector<int> degree(N);
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            degree[a] += 1;
            degree[b] += 1;
        }
        
        sort(degree.begin(), degree.end());
        
        long long res = 0;
        for(int i = 0; i < N; ++i){
            res += degree[i] * (i + 1LL);
        }
        
        return res;
    }
};