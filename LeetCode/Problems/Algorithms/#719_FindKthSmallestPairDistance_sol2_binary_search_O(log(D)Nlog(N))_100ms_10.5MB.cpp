class Solution {
private:
    int countPairsWithMaxDiff(vector<int>& nums, const int& MAX_DIFF){
        int pairsCnt = 0;
        for(int i = 0; i < nums.size(); ++i){
            int j = upper_bound(nums.begin(), nums.end(), nums[i] + MAX_DIFF) - nums.begin() - 1;
            pairsCnt += (j - i);
        }
        return pairsCnt;
    }
    
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums.back() - nums.front();
        while(l != r){
            int mid = (l + r) / 2;
            if(countPairsWithMaxDiff(nums, mid) >= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};