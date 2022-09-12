class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> minIdxOf;
        minIdxOf[0] = -1;
        
        int prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            prefSum %= k;
            if(minIdxOf.count(prefSum) && i - minIdxOf[prefSum] >= 2){
                return true;
            }
            if(!minIdxOf.count(prefSum)){
                minIdxOf[prefSum] = i;
            }
        }
        
        return false;
    }
};