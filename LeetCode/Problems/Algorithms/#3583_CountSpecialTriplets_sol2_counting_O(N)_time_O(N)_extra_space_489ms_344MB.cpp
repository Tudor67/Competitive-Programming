class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        unordered_map<int, int> leftCount;
        unordered_map<int, int> rightCount;
        for(int num: nums){
            rightCount[num] += 1;
        }

        int validTriplets = 0;
        for(int num: nums){
            rightCount[num] -= 1;
            if(leftCount.count(2 * num) && rightCount.count(2 * num)){
                validTriplets += (leftCount[2 * num] * (long long)rightCount[2 * num]) % MODULO;
                validTriplets %= MODULO;
            }
            leftCount[num] += 1;
        }

        return validTriplets;
    }
};