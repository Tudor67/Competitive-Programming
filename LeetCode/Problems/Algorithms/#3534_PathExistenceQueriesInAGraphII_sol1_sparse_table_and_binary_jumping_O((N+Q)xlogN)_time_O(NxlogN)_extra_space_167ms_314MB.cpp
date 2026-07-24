class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());
        
        const int Q = queries.size();
        const int U = sortedNums.size();
        const int LOG_U = log2(U);

        vector<vector<int>> jump(LOG_U + 1, vector<int>(U));
        for(int i = 0; i < U; ++i){
            jump[0][i] = upper_bound(sortedNums.begin() + i, sortedNums.end(), sortedNums[i] + maxDiff)
                         - sortedNums.begin() - 1;
        }

        for(int k = 1; k <= LOG_U; ++k){
            for(int i = 0; i < U; ++i){
                jump[k][i] = jump[k - 1][jump[k - 1][i]];
            }
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            if(queries[i][0] == queries[i][1]){
                continue;
            }
            
            int a = lower_bound(sortedNums.begin(), sortedNums.end(), nums[queries[i][0]]) - sortedNums.begin();
            int b = lower_bound(sortedNums.begin(), sortedNums.end(), nums[queries[i][1]]) - sortedNums.begin();

            if(a > b){
                swap(a, b);
            }

            int minSteps = 0;
            for(int k = LOG_U; k >= 0; --k){
                if(jump[k][a] < b){
                    a = jump[k][a];
                    minSteps += (1 << k);
                }
            }

            if(jump[0][a] >= b){
                res[i] = 1 + minSteps;
            }else{
                res[i] = -1;
            }
        }

        return res;
    }
};