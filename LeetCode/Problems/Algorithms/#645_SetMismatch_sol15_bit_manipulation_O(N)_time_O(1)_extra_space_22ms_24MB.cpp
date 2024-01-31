class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();

        int duplicateXorMissing = 0;
        for(int i = 1; i <= N; ++i){
            duplicateXorMissing ^= i;
            duplicateXorMissing ^= nums[i - 1];
        }

        int splitBit = 0;
        while(((duplicateXorMissing >> splitBit) & 1) == 0){
            splitBit += 1;
        }

        int candidate = 0;
        for(int i = 1; i <= N; ++i){
            if((i >> splitBit) & 1){
                candidate ^= i;
            }
            if((nums[i - 1] >> splitBit) & 1){
                candidate ^= nums[i - 1];
            }
        }

        int duplicate = candidate;
        if(find(nums.begin(), nums.end(), candidate) == nums.end()){
            duplicate = candidate ^ duplicateXorMissing;
        }

        return {duplicate, duplicate ^ duplicateXorMissing};
    }
};