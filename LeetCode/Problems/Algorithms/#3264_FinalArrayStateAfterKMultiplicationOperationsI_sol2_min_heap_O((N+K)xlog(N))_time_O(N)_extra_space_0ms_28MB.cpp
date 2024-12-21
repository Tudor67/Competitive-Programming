class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const int N = nums.size();

        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        vector<int> res = nums;
        for(int i = 0; i < N; ++i){
            minHeap.push({res[i], i});
        }

        for(int op = 1; op <= k; ++op){
            int i = minHeap.top().second;
            minHeap.pop();

            res[i] *= multiplier;
            minHeap.push({res[i], i});
        }

        return res;
    }
};