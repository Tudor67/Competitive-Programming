class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        vector<vector<int>> vSum = matrix;
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < M; ++j){
                vSum[i][j] += vSum[i - 1][j];
            }
        }
        
        int answer = 0;
        unordered_map<int, int> cnt;
        for(int i1 = 0; i1 < N; ++i1){
            for(int i2 = i1; i2 < N; ++i2){
                cnt.clear();
                cnt[0] = 1;
                int sum = 0;
                for(int j = 0; j < M; ++j){
                    sum += vSum[i2][j] - (i1 - 1 >= 0 ? vSum[i1 - 1][j] : 0);
                    if(cnt.find(sum - target) != cnt.end()){
                        answer += cnt[sum - target];
                    }
                    cnt[sum] += 1;
                }
            }
        }
        
        return answer;
    }
};