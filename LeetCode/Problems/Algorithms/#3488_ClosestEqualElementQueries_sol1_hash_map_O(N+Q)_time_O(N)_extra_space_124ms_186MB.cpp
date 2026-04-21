class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        unordered_map<int, int> numToLastIndex;
        vector<int> prev(N);
        vector<int> next(N);
        for(int i = 0; i < 2 * N; ++i){
            if(numToLastIndex.contains(nums[i % N])){
                prev[i % N] = numToLastIndex[nums[i % N]];
                next[prev[i % N]] = i % N;
            }
            numToLastIndex[nums[i % N]] = i % N;
        }

        vector<int> res(Q);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int i = queries[queryIndex];
            if(prev[i] == i){
                res[queryIndex] = -1;
            }else{
                int dist1 = abs(i - prev[i]);
                int dist2 = abs(i - next[i]);
                res[queryIndex] = min(min(dist1, N - dist1),
                                      min(dist2, N - dist2));
            }
        }

        return res;
    }
};