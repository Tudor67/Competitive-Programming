class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const int N = nums.size();

        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        for(int i = 0; i < N; ++i){
            minHeap.push({nums[i], i});
        }

        for(int op = 1; op <= k; ++op){
            int num = minHeap.top().first;
            int i = minHeap.top().second;
            minHeap.pop();
            minHeap.push({multiplier * num, i});
        }

        vector<int> res(N);
        while(!minHeap.empty()){
            res[minHeap.top().second] = minHeap.top().first;
            minHeap.pop();
        }

        return res;
    }
};