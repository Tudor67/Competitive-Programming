class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> prefSum(N);
        prefSum[0] = sortedNums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + sortedNums[i];
        }

        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            answer[i] = upper_bound(prefSum.begin(), prefSum.end(), queries[i]) - prefSum.begin();
        }

        return answer;
    }
};