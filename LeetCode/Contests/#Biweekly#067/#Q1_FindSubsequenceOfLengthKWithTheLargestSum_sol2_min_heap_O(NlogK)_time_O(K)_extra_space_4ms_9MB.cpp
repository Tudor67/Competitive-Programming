class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int N = nums.size();
        
        // Step 1: keep the k biggest nums (and their indices)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < N; ++i){
            minHeap.emplace(nums[i], i);
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        // Step 2: save indices of k biggest nums
        vector<int> indices(k);
        for(int i = 0; i < k; ++i){
            indices[i] = minHeap.top().second;
            minHeap.pop();
        }
        
        // Step 3: sort indices
        sort(indices.begin(), indices.end());
        
        // Step 4: create the answer subseq[i] = nums[indices[i]]
        vector<int> subseq(k);
        for(int i = 0; i < k; ++i){
            subseq[i] = nums[indices[i]];
        }
        
        return subseq;
    }
};