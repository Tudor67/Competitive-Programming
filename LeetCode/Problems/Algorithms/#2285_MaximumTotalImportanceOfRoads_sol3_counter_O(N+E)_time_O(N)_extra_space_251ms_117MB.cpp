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

        const int MAX_DEGREE = *max_element(degree.begin(), degree.end());
        vector<int> freq(MAX_DEGREE + 1);
        for(int node = 0; node < N; ++node){
            freq[degree[node]] += 1;
        }

        long long res = 0;
        long long i = 1;
        for(int d = 0; d <= MAX_DEGREE; ++d){
            while(freq[d] >= 1){
                freq[d] -= 1;
                res += d * i;
                i += 1;
            }
        }

        return res;
    }
};