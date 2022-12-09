class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> count(MAX_NUM + 1);
        for(int num: nums){
            count[num] += 1;
        }

        vector<int> prefCount(MAX_NUM + 1);
        prefCount[0] = count[0];
        for(int num = 1; num <= MAX_NUM; ++num){
            prefCount[num] = prefCount[num - 1] + count[num];
        }

        int validTriplets = 0;
        for(int num = 1; num <= MAX_NUM; ++num){
            validTriplets += prefCount[num - 1] * count[num] * (N - prefCount[num]);
        }

        return validTriplets;
    }
};