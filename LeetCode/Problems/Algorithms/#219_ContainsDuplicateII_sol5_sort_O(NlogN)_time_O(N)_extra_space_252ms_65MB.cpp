class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<pair<int, int>> sortedNumsAndIndices(N);
        for(int i = 0; i < N; ++i){
            sortedNumsAndIndices[i] = {nums[i], i};
        }
        
        sort(sortedNumsAndIndices.begin(), sortedNumsAndIndices.end());
        
        for(int i = 1; i < N; ++i){
            if(sortedNumsAndIndices[i].first == sortedNumsAndIndices[i - 1].first){
                if(sortedNumsAndIndices[i].second - sortedNumsAndIndices[i - 1].second <= k){
                    return true;
                }
            }
        }
        
        return false;
    }
};