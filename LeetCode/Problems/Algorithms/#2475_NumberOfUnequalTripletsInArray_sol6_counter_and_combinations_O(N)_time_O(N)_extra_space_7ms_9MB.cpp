class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }

        int totalTriplets = (N - 2) * (N - 1) * N / 6;
        int badTriplets = 0;
        for(const pair<int, int>& P: count){
            int numCount = P.second;
            badTriplets += (numCount - 2) * (numCount - 1) * numCount / 6;
            badTriplets += (N - numCount) * (numCount - 1) * numCount / 2;
        }

        return totalTriplets - badTriplets;
    }
};