class Solution {
public:
    int maxSumMinProduct(vector<int>& originalNums) {
        const int N = originalNums.size();
        const int MODULO = 1e9 + 7;
        
        vector<int> nums(N + 2, 0);
        copy(originalNums.begin(), originalNums.end(), nums.begin() + 1);
        
        vector<long long> prefixSum(N + 2);
        for(int i = 1; i <= N; ++i){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        priority_queue<pair<int, int>> maxHeap;
        
        // l[i]: the closest position to i such that nums[l[i]] < nums[i] and l[i] < i
        vector<int> l(N + 2);
        maxHeap.push({nums[0], 0});
        for(int i = 1; i <= N; ++i){
            while(maxHeap.top().first >= nums[i]){
                maxHeap.pop();
            }
            l[i] = maxHeap.top().second;
            maxHeap.push({nums[i], i});
        }
        
        while(!maxHeap.empty()){
            maxHeap.pop();
        }
        
        // r[i]: the closest position to i such that nums[i] > nums[r[i]] and i < r[i]
        vector<int> r(N + 2);
        maxHeap.push({nums[N + 1], N + 1});
        for(int i = N; i >= 1; --i){
            while(maxHeap.top().first >= nums[i]){
                maxHeap.pop();
            }
            r[i] = maxHeap.top().second;
            maxHeap.push({nums[i], i});
        }
        
        long long maxProduct = 0;
        for(int i = 1; i <= N; ++i){
            long long product = nums[i] * (prefixSum[r[i] - 1] - prefixSum[l[i]]);
            maxProduct = max(product, maxProduct);
        }
        
        return maxProduct % MODULO;
    }
};