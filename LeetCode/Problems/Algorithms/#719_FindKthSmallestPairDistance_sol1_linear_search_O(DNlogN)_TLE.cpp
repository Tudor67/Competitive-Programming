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
        
        int answer = 0;
        int minDist = 0;
        int maxDist = nums.back() - nums.front();
        for(int dist = minDist; dist <= maxDist; ++dist){
            if(countPairsWithMaxDiff(nums, dist) >= k){
                answer = dist;
                break;
            }
        }
        
        return answer;
    }
};