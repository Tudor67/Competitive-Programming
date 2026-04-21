class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }

        vector<int> res(Q);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int i = queries[queryIndex];
            const vector<int>& INDICES = numToIndices[nums[i]];

            if((int)INDICES.size() == 1){
                res[queryIndex] = -1;
            }else{
                auto it = lower_bound(INDICES.begin(), INDICES.end(), i);

                if(it == INDICES.begin()){
                    res[queryIndex] = i + N - INDICES.back();
                }else{
                    res[queryIndex] = i - *prev(it);
                }

                if(next(it) == INDICES.end()){
                    res[queryIndex] = min(res[queryIndex], N - i + INDICES.front());
                }else{
                    res[queryIndex] = min(res[queryIndex], *next(it) - i);
                }
            }
        }

        return res;
    }
};