class Solution {
public:
    int missingInteger(vector<int>& nums) {
        const int N = nums.size();

        int prefSum = nums[0];
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] + 1 == nums[i]){
                prefSum += nums[i];
            }else{
                break;
            }
        }

        unordered_set<int> numsSet(nums.begin(), nums.end());
        for(int x = prefSum; x < prefSum + N + 1; ++x){
            if(!numsSet.contains(x)){
                return x;
            }
        }
        
        return -1;
    }
};