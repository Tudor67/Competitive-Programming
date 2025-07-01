class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int N = nums.size();

        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        for(int i = 0; i < N; ++i){
            minHeap.push({nums[i], i});
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<bool> used(N, false);
        while(!minHeap.empty()){
            used[minHeap.top().second] = true;
            minHeap.pop();
        }

        vector<int> res;
        res.reserve(k);
        for(int i = 0; i < N; ++i){
            if(used[i]){
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};