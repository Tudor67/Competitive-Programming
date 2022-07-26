class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int N = nums1.size();
        
        map<int, int> count;
        for(int i = 0; i < N; ++i){
            int diff = abs(nums1[i] - nums2[i]);
            if(diff > 0){
                count[diff] += 1;
            }
        }
        
        priority_queue<pair<int, int>> maxHeap;
        for(const pair<int, int>& P: count){
            int diff = P.first;
            int diffCount = P.second;
            maxHeap.emplace(diff, diffCount);
        }
        
        int k = k1 + k2;
        while(!maxHeap.empty() && k > 0){
            int diff = maxHeap.top().first;
            int diffCount = maxHeap.top().second;
            maxHeap.pop();
            
            int take = min(k, diffCount);
            diffCount -= take;
            k -= take;
            
            if(diff - 1 > 0 && take > 0){
                int prevDiffCount = take;
                if(!maxHeap.empty() && maxHeap.top().first == diff - 1){
                    prevDiffCount += maxHeap.top().second;
                    maxHeap.pop();
                }
                maxHeap.emplace(diff - 1, prevDiffCount);
            }
            
            if(diffCount > 0){
                maxHeap.emplace(diff, diffCount);
            }
        }
        
        long long res = 0;
        while(!maxHeap.empty()){
            int diff = maxHeap.top().first;
            int diffCount = maxHeap.top().second;
            maxHeap.pop();
            
            res += (diffCount * 1LL * diff * 1LL * diff);
        }
        
        return res;
    }
};