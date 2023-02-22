class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        // At jth iteration:
        //    prefCount[x]: count of elements with values in range [0 .. x]
        //                  when we processed nums[0 .. j]
        vector<int> prefCount(N + 1);
        for(int j = 0; j < N; ++j){
            int ikPairs = 0;
            for(int l = j + 1; l < N; ++l){
                if(nums[j] < nums[l]){
                    res += ikPairs;
                }else{
                    ikPairs += prefCount[nums[l] - 1];
                }
            }

            for(int num = nums[j]; num <= N; ++num){
                prefCount[num] += 1;
            }
        }

        return res;
    }
};