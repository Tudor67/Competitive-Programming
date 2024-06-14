class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();

        int prefSum = 0;
        unordered_map<int, int> minIndexOf = {{0, -1}};
        for(int i = 0; i < N; ++i){
            prefSum = (prefSum + nums[i]) % k;
            if(minIndexOf.count(prefSum) && i - minIndexOf[prefSum] >= 2){
                return true;
            }
            if(!minIndexOf.count(prefSum)){
                minIndexOf[prefSum] = i;
            }
        }

        return false;
    }
};