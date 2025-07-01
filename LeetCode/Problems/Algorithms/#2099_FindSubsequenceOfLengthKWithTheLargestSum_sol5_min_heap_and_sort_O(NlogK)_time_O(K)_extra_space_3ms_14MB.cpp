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

        vector<int> resIndices;
        resIndices.reserve(k);
        while(!minHeap.empty()){
            resIndices.push_back(minHeap.top().second);
            minHeap.pop();
        }

        sort(resIndices.begin(), resIndices.end());

        vector<int> res;
        res.reserve(k);
        for(int i: resIndices){
            res.push_back(nums[i]);
        }

        return res;
    }
};