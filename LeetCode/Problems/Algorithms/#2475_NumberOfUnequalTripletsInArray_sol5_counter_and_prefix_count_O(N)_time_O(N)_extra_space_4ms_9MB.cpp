class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }

        int res = 0;
        int prefCount = 0;
        for(const pair<int, int>& P: count){
            int numCount = P.second;
            prefCount += numCount;
            res += (prefCount - numCount) * numCount * (N - prefCount);
        }

        return res;
    }
};