class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> minIndexOf;
        minIndexOf[0] = -1;
        
        int prefixSum = 0;
        for(int i = 0; i < N; ++i){
            prefixSum += nums[i];
            prefixSum %= k;
            if(minIndexOf.count(prefixSum) && i - minIndexOf[prefixSum] >= 2){
                return true;
            }
            if(!minIndexOf.count(prefixSum)){
                minIndexOf[prefixSum] = i;
            }
        }
        
        return false;
    }
};